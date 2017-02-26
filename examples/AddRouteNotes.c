
#include <stdio.h>
#include "../include/route4me.h"

static char key[] = "11111111111111111111111111111111";

int main(int argc, char* argv[])
{
    char route_id[] = "CA902292134DBC134EAF8363426BD247";
    char route_destination_id[] = "174405709A";
    char file_name[] = "add_address_to_route.json";
    char* data = NULL;
    struct MapPoint point = {0,1};

    deserialize(file_name, &data);

    init(key, 1);

    if (!add_route_notes(route_id, route_destination_id,"notes", "laptop", &point, data))
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

