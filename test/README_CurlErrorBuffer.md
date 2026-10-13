# cURL error-buffer regression

The cURL failure path copies a NUL-terminated error string into `m_err_msg`.
Its allocation must include the terminator; allocating only `strlen(message)`
writes one byte beyond the requested buffer.

Run the focused regression with Python 3 and a C compiler:

```sh
python3 test/CurlErrorBufferRegression.py --compiler cc
```

The fixture extracts the actual failure branch from `src/route4me.c`, compiles
it with a fake cURL error and a guarded allocator, and checks both the requested
allocation size and writes into the guard region. It exercises a normal error,
a longer error and an empty message. `--source PATH` can test an unmodified
baseline. Compiler selection accepts `CC` or `--compiler` as one executable.

No network calls, API keys or external SDK dependencies are used. This verifies
the changed error-buffer branch; it is not a full SDK build or integration test.
