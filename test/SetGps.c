
#include <stdio.h>
#include "../include/route4me.h"

static char key[] = "11111111111111111111111111111111";

int main(int argc, char* argv[])
{
    struct MapPoint point = {33.143840, -83.224660};

    json_object* props = json_object_new_object();
    json_object_object_add(props, "route_id", json_object_new_string("AC16E7D338B551013FF34266FE81A5EE"));
    json_object_object_add(props, "lat", json_object_new_double(point.lat));
    json_object_object_add(props, "lng", json_object_new_double(point.lng));
    json_object_object_add(props, "course", json_object_new_int(1));
    json_object_object_add(props, "speed", json_object_new_int(120));
    json_object_object_add(props, "device_type", json_object_new_string("iphone"));
    json_object_object_add(props, "device_guid", json_object_new_string("TEST_GPS"));
    json_object_object_add(props, "device_timestamp", json_object_new_string("2014-06-14%2017%3A43%3A35"));
    json_object_object_add(props, "member_id", json_object_new_int(1));
    json_object_object_add(props, "format", json_object_new_string("csv"));

    init(key, 1);

    if (!set_gps(props))
    {
       json_object* opt_lst = getJSONResponse();
       printf("%s\n", json_object_to_json_string(opt_lst));
    }

    struct response_data response = getCurrentResponse();
    printf("Return code: %d\n Response: %s\n", response.m_err_code, response.m_raw_resp);

    cleanUp();
	return 0;
}

