
#include <stdio.h>
#include <json.h>
#include "../include/route4me.h"

static char key[] = "11111111111111111111111111111111";

int main(int argc, char* argv[])
{
    init(key, 1);

    json_object* point1 = json_object_new_object();
    json_object_object_add(point1, "lng", json_object_new_double(-85.757308));
    json_object_object_add(point1, "lat", json_object_new_double(38.251698));
    json_object_object_add(point1, "is_depot", json_object_new_boolean(TRUE));
    json_object_object_add(point1, "time", json_object_new_int(100));
    json_object_object_add(point1, "sequence_no", json_object_new_int(0));
    json_object_object_add(point1, "address", json_object_new_string("455 S 4th St, Louisville, KY 40202"));

    json_object* point2 = json_object_new_object();
    json_object_object_add(point2, "lng", json_object_new_double(-85.793846));
    json_object_object_add(point2, "lat", json_object_new_double(38.141598));
    json_object_object_add(point2, "is_depot", json_object_new_boolean(TRUE));
    json_object_object_add(point2, "time", json_object_new_int(300));
    json_object_object_add(point2, "sequence_no", json_object_new_int(1));
    json_object_object_add(point2, "address", json_object_new_string("1604 PARKRIDGE PKWY, Louisville, KY, 40214"));

    json_object* addrs = json_object_new_array();
    json_object_array_add(addrs, point1);
    json_object_array_add(addrs, point2);

    json_object* params = json_object_new_object();
    json_object_object_add(params, "route_name", json_object_new_string("Single Driver Round Trip"));
    json_object_object_add(params, "algorithm_type", json_object_new_int(TSP));
    json_object_object_add(params, "remote_ip", json_object_new_int(0));
    json_object_object_add(params, "member_id", json_object_new_int(1));
    json_object_object_add(params, "route_time", json_object_new_int(0));
    json_object_object_add(params, "route_max_duration", json_object_new_int(86400));
    json_object_object_add(params, "optimize", json_object_new_string("Distance"));
    json_object_object_add(params, "distance_unit", json_object_new_string("mi"));
    json_object_object_add(params, "travel_mode", json_object_new_string("Driving"));
    json_object_object_add(params, "store_route", json_object_new_int(1));
    json_object_object_add(params, "device_type", json_object_new_string("web"));
    json_object_object_add(params, "vehicle_capacity", json_object_new_int(1));
    json_object_object_add(params, "vehicle_max_distance_mi", json_object_new_int(10000));
    json_object_object_add(params, "directions", json_object_new_int(1));

    if (!run_optimization(addrs, params))
    {
       json_object* opt_lst = getJSONResponse();
       printf("%s\n", json_object_to_json_string(opt_lst));
    }

    struct response_data response = getCurrentResponse();
    printf("Return code: %d\n Response: %s\n", response.m_err_code, response.m_raw_resp);

    cleanUp();
	return 0;
}

