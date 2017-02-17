
#include <stdio.h>
#include "../include/route4me.h"

static char key[] = "11111111111111111111111111111111";

int main(int argc, char* argv[])
{
    init(key, 0);

    char data_file[] = "poly.json";
    char id[] = "A1";
    char* data = NULL;

    if (deserialize(data_file, &data) == -1)
    {
        printf("Missing poly.json\n");
        return -1;
    }

    if (!get_multiple_routes(data_file, data))
    {
       json_object* opt_lst = getJSONResponse();
       printf("%s\n", json_object_to_json_string(opt_lst));
    }

    struct response_data response = getCurrentResponse();
    printf("Return code: %d\n Response: %s\n", response.m_err_code, response.m_raw_resp);

    cleanUp();
	return 0;
}

