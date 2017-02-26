
#include <stdio.h>
#include "../include/route4me.h"

static char key[] = "11111111111111111111111111111111";

int main(int argc, char* argv[])
{
    char file_name[] = "add_account_data.json";
    char* data = NULL;
    struct MapPoint point = {0,1};

    if (deserialize(file_name, &data))
    {
        printf("File add_account_data.json not found!\n");
        return -1;
    }

    init(key, 1);

    if (!modify_config(data, REQ_POST))
    {
       json_object* opt_lst = getJSONResponse();
       printf("%s\n", json_object_to_json_string(opt_lst));
    }

    struct response_data response = getCurrentResponse();
    printf("Return code: %d\n Response: %s\n", response.m_err_code, response.m_raw_resp);

    if (data)
    {
        free(data);
    }

    cleanUp();
	return 0;
}

