
#include <json.h>
#include <stdio.h>
#include "../include/route4me.h"


int deserialize(const char* szFile, char** strJson)
{
    size_t len = 0;
    int ret = -1;
    FILE* fp = fopen(szFile, "r");
    if (fp != NULL)
    {        
        fseek(fp, 0, SEEK_END);
        len = ftell(fp);
        rewind(fp);
        *strJson = malloc(len);
        fread(*strJson, sizeof(char), len, fp);
        fclose(fp);
        ret = 0;
    }
    return ret;
}
