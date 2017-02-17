
#include <string.h>

int str_empty(char* str)
{
    if ((strlen(str) == 0) || (*str == '\0' ))
    {
        return 1;
    }
    return 0;
}

void strip_quotes(char* line, const char* quoted_line)
{
    int i;
    for (i = 0; i < strlen(quoted_line) - 1; ++i)
    {
        if (i > 0)
        {
            line[i-1] = quoted_line[i];
        }
    }
    line[i] = '\0';
}
