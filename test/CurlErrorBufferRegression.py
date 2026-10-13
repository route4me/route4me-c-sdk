"""Execute the SDK's cURL-error branch with a guarded allocator.

No API calls or SDK dependency installation are needed. This is a focused
source-branch regression, not a complete SDK/cURL integration test.
Run with --compiler /path/to/cc; --source can select an unmodified baseline.
"""
import argparse
import os
import re
import shutil
import subprocess
import tempfile
from pathlib import Path

FIXTURE = r'''
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ERR_CURL_RESP 100
static struct { int m_err_code; char *m_err_msg; } current_response;
static struct { char *memory; size_t size; } chunk;
static const char *error_message;
static size_t requested_size;
static unsigned char *allocation;

static void *guarded_realloc(void *old, size_t size)
{
    free(old);
    requested_size = size;
    allocation = (unsigned char *)malloc(size + 16);
    if (!allocation) { fputs("fixture allocation failed\n", stderr); exit(2); }
    memset(allocation, 0xA5, size + 16);
    return allocation;
}

static const char *curl_easy_strerror(int res)
{
    (void)res;
    return error_message;
}

#define realloc guarded_realloc
static int run_error_branch(void)
{
    int res = 7;
    chunk.memory = (char *)malloc(1);
    {
__SDK_ERROR_BRANCH__
    }
}
#undef realloc

int main(void)
{
    const char *cases[] = {"Could not resolve host", "SSL peer certificate verification failed", ""};
    size_t i, j;
    int failed = 0;
    for (i = 0; i < sizeof(cases) / sizeof(cases[0]); ++i) {
        size_t required;
        error_message = cases[i];
        required = strlen(error_message) + 1;
        if (run_error_branch() != ERR_CURL_RESP) ++failed;
        if (current_response.m_err_code != ERR_CURL_RESP) ++failed;
        if (requested_size < required) {
            fprintf(stderr, "case %lu: allocated %lu bytes, need %lu including NUL\n",
                    (unsigned long)i, (unsigned long)requested_size, (unsigned long)required);
            ++failed;
        }
        for (j = requested_size; j < requested_size + 16; ++j) {
            if (allocation[j] != 0xA5) {
                fprintf(stderr, "case %lu: write beyond requested allocation\n", (unsigned long)i);
                ++failed;
                break;
            }
        }
        if (strcmp(current_response.m_err_msg, error_message) != 0) ++failed;
        free(current_response.m_err_msg);
        current_response.m_err_msg = NULL;
    }
    if (failed) return 1;
    puts("3 guarded cURL error-buffer cases passed");
    return 0;
}
'''

def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--compiler', default=os.environ.get('CC'))
    parser.add_argument('--source', type=Path, default=Path(__file__).resolve().parents[1] / 'src' / 'route4me.c')
    parser.add_argument('--temp-dir', type=Path, help='Optional writable parent for generated fixture files.')
    args = parser.parse_args()
    compiler = args.compiler or next((shutil.which(c) for c in ('cc', 'gcc', 'clang', 'tcc') if shutil.which(c)), None)
    if not compiler:
        parser.error('Set CC or --compiler to a C compiler executable.')
    compiler = shutil.which(compiler) or str(Path(compiler).resolve())
    env = dict(os.environ)
    env['PATH'] = str(Path(compiler).parent) + os.pathsep + env.get('PATH', '')
    source = args.source.read_text(encoding='utf-8')
    request = source.split('static int request(', 1)[1]
    error_path = request.split('CURLcode res = curl_easy_perform(curl);', 1)[1]
    match = re.search(r'if\s*\(\s*res\s*!=\s*CURLE_OK\s*\)\s*\{([^{}]+)\}', error_path)
    if not match:
        parser.error('SDK cURL-error branch changed; update the focused fixture deliberately.')
    fixture = FIXTURE.replace('__SDK_ERROR_BRANCH__', match.group(1))
    scratch = (args.temp_dir or Path(tempfile.gettempdir())).resolve()
    scratch.mkdir(parents=True, exist_ok=True)
    temp = tempfile.TemporaryDirectory(prefix='route4me-curl-error-', dir=scratch)
    try:
        root = Path(temp.name).resolve()
        if root.parent != scratch:
            raise RuntimeError('Fixture directory escapes configured temporary parent.')
        test_source = root / 'curl_error.c'
        executable = root / ('curl_error.exe' if os.name == 'nt' else 'curl_error')
        test_source.write_text(fixture, encoding='utf-8')
        subprocess.run([compiler, str(test_source), '-o', str(executable)], check=True, env=env)
        subprocess.run([str(executable)], check=True, env=env)
    finally:
        if Path(temp.name).resolve().parent != scratch:
            raise RuntimeError('Unexpected cleanup target; fixture preserved.')
        temp.cleanup()

if __name__ == '__main__':
    main()
