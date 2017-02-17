
#include <stdio.h>
#include "../include/route4me.h"

static char key[] = "11111111111111111111111111111111";

int main(int argc, char* argv[])
{
    char opt_id[] = "07372F2CF3814EC6DFFAFE92E22771AA";
    char file_name[] = "address_for_optimization.json";
    int reoptimize = 1;
    char* data = NULL;

    if (0 != deserialize(file_name, &data))
    {
        printf("File address_for_optimization.json not found!\n");
        return -1;
    }

    init(key, 1);

    if (!add_address_to_optimization(opt_id, data, reoptimize))
    {
       json_object* opt_lst = getJSONResponse();
       printf("%s\n", json_object_to_json_string(opt_lst));
    }

    struct response_data response = getCurrentResponse();
    printf("Return code: %d\n Response: %s\n", response.m_err_code, response.m_raw_resp);

    cleanUp();
	return 0;
}

