
#include <stdio.h>
#include "../include/route4me.h"

static char key[] = "11111111111111111111111111111111";

int main(int argc, char* argv[])
{
    char* data = NULL;
    init(key, 0);

    if (deserialize("create_poly_zone_data.json", &data))
    {
        printf("Data file not found!\n");
    }

    if (!add_territory(data))
    {
       json_object* opt_lst = getJSONResponse();
       json_object* opt_id = json_object_object_get(opt_lst, "territory_id");
       printf("Territory added: %s\n", json_object_to_json_string(opt_id));
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

