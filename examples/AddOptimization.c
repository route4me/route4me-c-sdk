
#include <stdio.h>
#include <json.h>
#include "../include/route4me.h"

static char key[] = "11111111111111111111111111111111";

int main(int argc, char* argv[])
{
    init(key, 1);
    const char file_name[] = "new_optimization.json";
    char* data = NULL;

    if (deserialize(file_name, &data))
    {
        printf("Data file is not found!\n");
        return -1;
    }

    if (!add_optimization(data))
    {
        json_object* opt_lst = getJSONResponse();
        printf("%s\n", json_object_to_json_string(opt_lst));
    }
    struct response_data response = getCurrentResponse();
    printf("Return code: %d\n Response: %s\n", response.m_err_code, response.m_raw_resp);

    cleanUp();
	return 0;
}

