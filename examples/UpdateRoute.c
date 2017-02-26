
#include <stdio.h>
#include "../include/route4me.h"

static char key[] = "11111111111111111111111111111111";

int main(int argc, char* argv[])
{
    init(key, 0);
    char* data = NULL;

    char route_id[] = "CA902292134DBC134EAF8363426BD247";
    char dest_id[] = "174405709A";
    char file_name[] = "update_route_destination_custom_data.json";

    deserialize(file_name, &data);
    printf("Data: %s\n", data);

    if (!update_route(route_id, dest_id, data))
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

