
#include <stdio.h>
#include <json.h>
#include "../include/route4me.h"

static char key[] = "11111111111111111111111111111111";

#define ADD_ADDRESS(x) json_object_array_add(addrs, point##x)

int main(int argc, char* argv[])
{
    int i;
    init(key, 1);

    json_object* point1 = json_object_new_object();
    json_object_object_add(point1, "address", json_object_new_string("40 Mercer st, New York, NY"));
    json_object_object_add(point1, "lng", json_object_new_double(-74.0013082));
    json_object_object_add(point1, "lat", json_object_new_double(40.7213583));
    json_object_object_add(point1, "is_depot", json_object_new_boolean(TRUE));
    json_object_object_add(point1, "time", json_object_new_int(0));

    json_object* point2 = json_object_new_object();
    json_object_object_add(point2, "address", json_object_new_string("new york, ny"));
    json_object_object_add(point2, "lng", json_object_new_double(-74.0059729));
    json_object_object_add(point2, "lat", json_object_new_double(40.7142691));
    json_object_object_add(point2, "is_depot", json_object_new_boolean(FALSE));
    json_object_object_add(point2, "time", json_object_new_int(0));

    json_object* point3 = json_object_new_object();
    json_object_object_add(point3, "address", json_object_new_string("Manhatten Island NYC"));
    json_object_object_add(point3, "lng", json_object_new_double(-74.0059729));
    json_object_object_add(point3, "lat", json_object_new_double(40.7142691));
    json_object_object_add(point3, "is_depot", json_object_new_boolean(FALSE));
    json_object_object_add(point3, "time", json_object_new_int(0));

    json_object* point4 = json_object_new_object();
    json_object_object_add(point4, "address", json_object_new_string("503 W139 St, NY,NY"));
    json_object_object_add(point4, "lng", json_object_new_double(-74.0091848));
    json_object_object_add(point4, "lat", json_object_new_double(40.7109062));
    json_object_object_add(point4, "is_depot", json_object_new_boolean(FALSE));
    json_object_object_add(point4, "time", json_object_new_int(0));

    json_object* point5 = json_object_new_object();
    json_object_object_add(point5, "address", json_object_new_string("203 grand st, new york, ny"));
    json_object_object_add(point5, "lng", json_object_new_double(-73.9967320));
    json_object_object_add(point5, "lat", json_object_new_double(40.7188990));
    json_object_object_add(point5, "is_depot", json_object_new_boolean(FALSE));
    json_object_object_add(point5, "time", json_object_new_int(0));

    json_object* point6 = json_object_new_object();
    json_object_object_add(point6, "address", json_object_new_string("119 Church Street"));
    json_object_object_add(point6, "lng", json_object_new_double(-74.0088238));
    json_object_object_add(point6, "lat", json_object_new_double(40.7137757));
    json_object_object_add(point6, "is_depot", json_object_new_boolean(FALSE));
    json_object_object_add(point6, "time", json_object_new_int(0));

    json_object* point7 = json_object_new_object();
    json_object_object_add(point7, "address", json_object_new_string("new york ny"));
    json_object_object_add(point7, "lng", json_object_new_double(-74.0059729));
    json_object_object_add(point7, "lat", json_object_new_double(40.7142691));
    json_object_object_add(point7, "is_depot", json_object_new_boolean(FALSE));
    json_object_object_add(point7, "time", json_object_new_int(0));

    json_object* point8 = json_object_new_object();
    json_object_object_add(point8, "address", json_object_new_string("ny"));
    json_object_object_add(point8, "lng", json_object_new_double(-74.0059729));
    json_object_object_add(point8, "lat", json_object_new_double(40.7142691));
    json_object_object_add(point8, "is_depot", json_object_new_boolean(FALSE));
    json_object_object_add(point8, "time", json_object_new_int(0));

    json_object* point9 = json_object_new_object();
    json_object_object_add(point9, "address", json_object_new_string("broadway street, new york"));
    json_object_object_add(point9, "lng", json_object_new_double(-74.0020849));
    json_object_object_add(point9, "lat", json_object_new_double(40.7191551));
    json_object_object_add(point9, "is_depot", json_object_new_boolean(FALSE));
    json_object_object_add(point9, "time", json_object_new_int(0));

    json_object* point10 = json_object_new_object();
    json_object_object_add(point10, "address", json_object_new_string("Ground Zero, Vesey-Liberty-Church-West Streets New York NY 10038"));
    json_object_object_add(point10, "lng", json_object_new_double(-74.0116602));
    json_object_object_add(point10, "lat", json_object_new_double(40.7233126));
    json_object_object_add(point10, "is_depot", json_object_new_boolean(FALSE));
    json_object_object_add(point10, "time", json_object_new_int(0));

    json_object* point11 = json_object_new_object();
    json_object_object_add(point11, "address", json_object_new_string("226 ilyssa way staten lsland ny"));
    json_object_object_add(point11, "lng", json_object_new_double(-74.0059729));
    json_object_object_add(point11, "lat", json_object_new_double(40.7142691));
    json_object_object_add(point11, "is_depot", json_object_new_boolean(FALSE));
    json_object_object_add(point11, "time", json_object_new_int(0));

    json_object* point12 = json_object_new_object();
    json_object_object_add(point12, "address", json_object_new_string("185 franklin st."));
    json_object_object_add(point12, "lng", json_object_new_double(-74.0097670));
    json_object_object_add(point12, "lat", json_object_new_double(40.7192099));
    json_object_object_add(point12, "is_depot", json_object_new_boolean(FALSE));
    json_object_object_add(point12, "time", json_object_new_int(0));

    json_object* point13 = json_object_new_object();
    json_object_object_add(point13, "address", json_object_new_string("new york city,"));
    json_object_object_add(point13, "lng", json_object_new_double(-74.0059729));
    json_object_object_add(point13, "lat", json_object_new_double(40.7142691));
    json_object_object_add(point13, "is_depot", json_object_new_boolean(FALSE));
    json_object_object_add(point13, "time", json_object_new_int(0));

    json_object* point14 = json_object_new_object();
    json_object_object_add(point14, "address", json_object_new_string("11 e. broaway 11038"));
    json_object_object_add(point14, "lng", json_object_new_double(-73.9974019));
    json_object_object_add(point14, "lat", json_object_new_double(40.7132060));
    json_object_object_add(point14, "is_depot", json_object_new_boolean(FALSE));
    json_object_object_add(point14, "time", json_object_new_int(0));

    json_object* point15 = json_object_new_object();
    json_object_object_add(point15, "address", json_object_new_string("Brooklyn Bridge, NY"));
    json_object_object_add(point15, "lng", json_object_new_double(-73.9962503));
    json_object_object_add(point15, "lat", json_object_new_double(40.7053804));
    json_object_object_add(point15, "is_depot", json_object_new_boolean(FALSE));
    json_object_object_add(point15, "time", json_object_new_int(0));

    json_object* point16 = json_object_new_object();
    json_object_object_add(point16, "address", json_object_new_string("World Trade Center Site, NY"));
    json_object_object_add(point16, "lng", json_object_new_double(-74.0122990));
    json_object_object_add(point16, "lat", json_object_new_double(40.7114980));
    json_object_object_add(point16, "is_depot", json_object_new_boolean(FALSE));
    json_object_object_add(point16, "time", json_object_new_int(0));

    json_object* point17 = json_object_new_object();
    json_object_object_add(point17, "address", json_object_new_string("New York Stock Exchange, NY"));
    json_object_object_add(point17, "lng", json_object_new_double(-74.0116342));
    json_object_object_add(point17, "lat", json_object_new_double(40.7074242));
    json_object_object_add(point17, "is_depot", json_object_new_boolean(FALSE));
    json_object_object_add(point17, "time", json_object_new_int(0));

    json_object* point18 = json_object_new_object();
    json_object_object_add(point18, "address", json_object_new_string("Wall Street, NY"));
    json_object_object_add(point18, "lng", json_object_new_double(-74.0079781));
    json_object_object_add(point18, "lat", json_object_new_double(40.7079825));
    json_object_object_add(point18, "is_depot", json_object_new_boolean(FALSE));
    json_object_object_add(point18, "time", json_object_new_int(0));

    json_object* point19 = json_object_new_object();
    json_object_object_add(point19, "address", json_object_new_string("Trinity Church, NY"));
    json_object_object_add(point19, "lng", json_object_new_double(-74.0120511));
    json_object_object_add(point19, "lat", json_object_new_double(40.7081426));
    json_object_object_add(point19, "is_depot", json_object_new_boolean(FALSE));
    json_object_object_add(point19, "time", json_object_new_int(0));

    json_object* point20 = json_object_new_object();
    json_object_object_add(point20, "address", json_object_new_string("World Financial Center, NY"));
    json_object_object_add(point20, "lng", json_object_new_double(-74.0154930));
    json_object_object_add(point20, "lat", json_object_new_double(40.7104750));
    json_object_object_add(point20, "is_depot", json_object_new_boolean(FALSE));
    json_object_object_add(point20, "time", json_object_new_int(0));

    json_object* point21 = json_object_new_object();
    json_object_object_add(point21, "address", json_object_new_string("Federal Hall, NY"));
    json_object_object_add(point21, "lng", json_object_new_double(-74.0102734));
    json_object_object_add(point21, "lat", json_object_new_double(40.7073034));
    json_object_object_add(point21, "is_depot", json_object_new_boolean(FALSE));
    json_object_object_add(point21, "time", json_object_new_int(0));

    json_object* point22 = json_object_new_object();
    json_object_object_add(point22, "address", json_object_new_string("Flatiron Building, NY"));
    json_object_object_add(point22, "lng", json_object_new_double(-74.0059729));
    json_object_object_add(point22, "lat", json_object_new_double(40.7142691));
    json_object_object_add(point22, "is_depot", json_object_new_boolean(FALSE));
    json_object_object_add(point22, "time", json_object_new_int(0));

    json_object* point23 = json_object_new_object();
    json_object_object_add(point23, "address", json_object_new_string("South Street Seaport, NY"));
    json_object_object_add(point23, "lng", json_object_new_double(-74.0036380));
    json_object_object_add(point23, "lat", json_object_new_double(40.7069210));
    json_object_object_add(point23, "is_depot", json_object_new_boolean(FALSE));
    json_object_object_add(point23, "time", json_object_new_int(0));

    json_object* point24 = json_object_new_object();
    json_object_object_add(point24, "address", json_object_new_string("Rockefeller Center, NY"));
    json_object_object_add(point24, "lng", json_object_new_double(-74.0059729));
    json_object_object_add(point24, "lat", json_object_new_double(40.7142691));
    json_object_object_add(point24, "is_depot", json_object_new_boolean(FALSE));
    json_object_object_add(point24, "time", json_object_new_int(0));

    json_object* point25 = json_object_new_object();
    json_object_object_add(point25, "address", json_object_new_string("FAO Schwarz, NY"));
    json_object_object_add(point25, "lng", json_object_new_double(-74.0059729));
    json_object_object_add(point25, "lat", json_object_new_double(40.7142691));
    json_object_object_add(point25, "is_depot", json_object_new_boolean(FALSE));
    json_object_object_add(point25, "time", json_object_new_int(0));

    json_object* point26 = json_object_new_object();
    json_object_object_add(point26, "address", json_object_new_string("Woolworth Building, NY"));
    json_object_object_add(point26, "lng", json_object_new_double(-74.0083309));
    json_object_object_add(point26, "lat", json_object_new_double(40.7123903));
    json_object_object_add(point26, "is_depot", json_object_new_boolean(FALSE));
    json_object_object_add(point26, "time", json_object_new_int(0));

    json_object* point27 = json_object_new_object();
    json_object_object_add(point27, "address", json_object_new_string("Met Life Building, NY"));
    json_object_object_add(point27, "lng", json_object_new_double(-74.0059729));
    json_object_object_add(point27, "lat", json_object_new_double(40.7142691));
    json_object_object_add(point27, "is_depot", json_object_new_boolean(FALSE));
    json_object_object_add(point27, "time", json_object_new_int(0));

    json_object* point28 = json_object_new_object();
    json_object_object_add(point28, "address", json_object_new_string("SOHO/Tribeca, NY"));
    json_object_object_add(point28, "lng", json_object_new_double(-74.0120170));
    json_object_object_add(point28, "lat", json_object_new_double(40.7185650));
    json_object_object_add(point28, "is_depot", json_object_new_boolean(FALSE));
    json_object_object_add(point28, "time", json_object_new_int(0));

    json_object* point29 = json_object_new_object();
    json_object_object_add(point29, "address", json_object_new_string("City Hall, NY, NY"));
    json_object_object_add(point29, "lng", json_object_new_double(-74.0058663));
    json_object_object_add(point29, "lat", json_object_new_double(40.7127047));
    json_object_object_add(point29, "is_depot", json_object_new_boolean(FALSE));
    json_object_object_add(point29, "time", json_object_new_int(0));

    json_object* point30 = json_object_new_object();
    json_object_object_add(point30, "address", json_object_new_string("Met Life Building, NY"));
    json_object_object_add(point30, "lng", json_object_new_double(-74.0059729));
    json_object_object_add(point30, "lat", json_object_new_double(40.7142691));
    json_object_object_add(point30, "is_depot", json_object_new_boolean(FALSE));
    json_object_object_add(point30, "time", json_object_new_int(0));

    json_object* addrs = json_object_new_array();    

    ADD_ADDRESS(1);
    ADD_ADDRESS(2);
    ADD_ADDRESS(3);
    ADD_ADDRESS(4);
    ADD_ADDRESS(5);
    ADD_ADDRESS(6);
    ADD_ADDRESS(7);
    ADD_ADDRESS(8);
    ADD_ADDRESS(9);
    ADD_ADDRESS(10);
    ADD_ADDRESS(11);
    ADD_ADDRESS(12);
    ADD_ADDRESS(13);
    ADD_ADDRESS(14);
    ADD_ADDRESS(15);
    ADD_ADDRESS(16);
    ADD_ADDRESS(17);
    ADD_ADDRESS(18);
    ADD_ADDRESS(19);
    ADD_ADDRESS(20);
    ADD_ADDRESS(21);
    ADD_ADDRESS(22);
    ADD_ADDRESS(23);
    ADD_ADDRESS(24);
    ADD_ADDRESS(25);
    ADD_ADDRESS(26);
    ADD_ADDRESS(27);
    ADD_ADDRESS(28);
    ADD_ADDRESS(29);
    ADD_ADDRESS(30);

    json_object* params = json_object_new_object();
    json_object_object_add(params, "route_name", json_object_new_string("Multiple Depots Multiple Drivers Trip"));
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

