
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
    json_object_object_add(point1, "address", json_object_new_string("455 S 4th St, Louisville, KY 40202"));
    json_object_object_add(point1, "lng", json_object_new_double(-85.757308));
    json_object_object_add(point1, "lat", json_object_new_double(38.251698));
    json_object_object_add(point1, "is_depot", json_object_new_boolean(TRUE));
    json_object_object_add(point1, "time", json_object_new_int(300));
    json_object_object_add(point1, "time_window_start", json_object_new_int(28800));
    json_object_object_add(point1, "time_window_end", json_object_new_int(30477));

    json_object* point2 = json_object_new_object();
    json_object_object_add(point2, "address", json_object_new_string("1604 PARKRIDGE PKWY, Louisville, KY, 40214"));
    json_object_object_add(point2, "lng", json_object_new_double(-85.793846));
    json_object_object_add(point2, "lat", json_object_new_double(38.141598));
    json_object_object_add(point2, "is_depot", json_object_new_boolean(FALSE));
    json_object_object_add(point2, "time", json_object_new_int(300));
    json_object_object_add(point2, "time_window_start", json_object_new_int(30477));
    json_object_object_add(point2, "time_window_end", json_object_new_int(33406));

    json_object* point3 = json_object_new_object();
    json_object_object_add(point3, "address", json_object_new_string("1407 א53MCCOY, Louisville, KY, 40215"));
    json_object_object_add(point3, "lng", json_object_new_double(-85.786514));
    json_object_object_add(point3, "lat", json_object_new_double(38.202496));
    json_object_object_add(point3, "is_depot", json_object_new_boolean(FALSE));
    json_object_object_add(point3, "time", json_object_new_int(300));
    json_object_object_add(point3, "time_window_start", json_object_new_int(33406));
    json_object_object_add(point3, "time_window_end", json_object_new_int(36228));

    json_object* point4 = json_object_new_object();
    json_object_object_add(point4, "address", json_object_new_string("4805 BELLEVUE AVE, Louisville, KY, 40215"));
    json_object_object_add(point4, "lng", json_object_new_double(-85.774864));
    json_object_object_add(point4, "lat", json_object_new_double(38.178844));
    json_object_object_add(point4, "is_depot", json_object_new_boolean(FALSE));
    json_object_object_add(point4, "time", json_object_new_int(300));
    json_object_object_add(point4, "time_window_start", json_object_new_int(36228));
    json_object_object_add(point4, "time_window_end", json_object_new_int(37518));

    json_object* point5 = json_object_new_object();
    json_object_object_add(point5, "address", json_object_new_string("730 CECIL AVENUE, Louisville, KY, 40211"));
    json_object_object_add(point5, "lng", json_object_new_double(-85.821121));
    json_object_object_add(point5, "lat", json_object_new_double(38.248684));
    json_object_object_add(point5, "is_depot", json_object_new_boolean(FALSE));
    json_object_object_add(point5, "time", json_object_new_int(300));
    json_object_object_add(point5, "time_window_start", json_object_new_int(37518));
    json_object_object_add(point5, "time_window_end", json_object_new_int(39550));

    json_object* point6 = json_object_new_object();
    json_object_object_add(point6, "address", json_object_new_string("650 SOUTH 29TH ST UNIT 315, Louisville, KY, 40211"));
    json_object_object_add(point6, "lng", json_object_new_double(-85.800034));
    json_object_object_add(point6, "lat", json_object_new_double(38.251923));
    json_object_object_add(point6, "is_depot", json_object_new_boolean(FALSE));
    json_object_object_add(point6, "time", json_object_new_int(300));
    json_object_object_add(point6, "time_window_start", json_object_new_int(39550));
    json_object_object_add(point6, "time_window_end", json_object_new_int(41348));

    json_object* point7 = json_object_new_object();
    json_object_object_add(point7, "address", json_object_new_string("4629 HILLSIDE DRIVE, Louisville, KY, 40216"));
    json_object_object_add(point7, "lng", json_object_new_double(-85.824638));
    json_object_object_add(point7, "lat", json_object_new_double(38.176067));
    json_object_object_add(point7, "is_depot", json_object_new_boolean(FALSE));
    json_object_object_add(point7, "time", json_object_new_int(300));
    json_object_object_add(point7, "time_window_start", json_object_new_int(41348));
    json_object_object_add(point7, "time_window_end", json_object_new_int(42261));

    json_object* point8 = json_object_new_object();
    json_object_object_add(point8, "address", json_object_new_string("4738 BELLEVUE AVE, Louisville, KY, 40215"));
    json_object_object_add(point8, "lng", json_object_new_double(-85.775558));
    json_object_object_add(point8, "lat", json_object_new_double(38.179806));
    json_object_object_add(point8, "is_depot", json_object_new_boolean(FALSE));
    json_object_object_add(point8, "time", json_object_new_int(300));
    json_object_object_add(point8, "time_window_start", json_object_new_int(42261));
    json_object_object_add(point8, "time_window_end", json_object_new_int(45195));

    json_object* point9 = json_object_new_object();
    json_object_object_add(point9, "address", json_object_new_string("318 SO. 39TH STREET, Louisville, KY, 40212"));
    json_object_object_add(point9, "lng", json_object_new_double(-85.815094));
    json_object_object_add(point9, "lat", json_object_new_double(38.259335));
    json_object_object_add(point9, "is_depot", json_object_new_boolean(FALSE));
    json_object_object_add(point9, "time", json_object_new_int(300));
    json_object_object_add(point9, "time_window_start", json_object_new_int(45195));
    json_object_object_add(point9, "time_window_end", json_object_new_int(46549));

    json_object* point10 = json_object_new_object();
    json_object_object_add(point10, "address", json_object_new_string("1324 BLUEGRASS AVE, Louisville, KY, 40215"));
    json_object_object_add(point10, "lng", json_object_new_double(-85.785118));
    json_object_object_add(point10, "lat", json_object_new_double(38.179253));
    json_object_object_add(point10, "is_depot", json_object_new_boolean(FALSE));
    json_object_object_add(point10, "time", json_object_new_int(300));
    json_object_object_add(point10, "time_window_start", json_object_new_int(46549));
    json_object_object_add(point10, "time_window_end", json_object_new_int(47353));

    json_object* point11 = json_object_new_object();
    json_object_object_add(point11, "address", json_object_new_string("7305 ROYAL WOODS DR, Louisville, KY, 40214"));
    json_object_object_add(point11, "lng", json_object_new_double(-85.792854));
    json_object_object_add(point11, "lat", json_object_new_double(38.162472));
    json_object_object_add(point11, "is_depot", json_object_new_boolean(FALSE));
    json_object_object_add(point11, "time", json_object_new_int(300));
    json_object_object_add(point11, "time_window_start", json_object_new_int(47353));
    json_object_object_add(point11, "time_window_end", json_object_new_int(50924));

    json_object* point12 = json_object_new_object();
    json_object_object_add(point12, "address", json_object_new_string("1661 W HILL ST, Louisville, KY, 40210"));
    json_object_object_add(point12, "lng", json_object_new_double(-85.783966));
    json_object_object_add(point12, "lat", json_object_new_double(38.229584));
    json_object_object_add(point12, "is_depot", json_object_new_boolean(FALSE));
    json_object_object_add(point12, "time", json_object_new_int(300));
    json_object_object_add(point12, "time_window_start", json_object_new_int(50924));
    json_object_object_add(point12, "time_window_end", json_object_new_int(51392));

    json_object* point13 = json_object_new_object();
    json_object_object_add(point13, "address", json_object_new_string("3222 KINGSWOOD WAY, Louisville, KY, 40216"));
    json_object_object_add(point13, "lng", json_object_new_double(-85.822594));
    json_object_object_add(point13, "lat", json_object_new_double(38.210606));
    json_object_object_add(point13, "is_depot", json_object_new_boolean(FALSE));
    json_object_object_add(point13, "time", json_object_new_int(300));
    json_object_object_add(point13, "time_window_start", json_object_new_int(51392));
    json_object_object_add(point13, "time_window_end", json_object_new_int(52451));

    json_object* point14 = json_object_new_object();
    json_object_object_add(point14, "address", json_object_new_string("1922 PALATKA RD, Louisville, KY, 40214"));
    json_object_object_add(point14, "lng", json_object_new_double(-85.796783));
    json_object_object_add(point14, "lat", json_object_new_double(38.153767));
    json_object_object_add(point14, "is_depot", json_object_new_boolean(FALSE));
    json_object_object_add(point14, "time", json_object_new_int(300));
    json_object_object_add(point14, "time_window_start", json_object_new_int(52451));
    json_object_object_add(point14, "time_window_end", json_object_new_int(55631));

    json_object* point15 = json_object_new_object();
    json_object_object_add(point15, "address", json_object_new_string("1314 SOUTH 26TH STREET, Louisville, KY, 40210"));
    json_object_object_add(point15, "lng", json_object_new_double(-85.796852));
    json_object_object_add(point15, "lat", json_object_new_double(38.235847));
    json_object_object_add(point15, "is_depot", json_object_new_boolean(FALSE));
    json_object_object_add(point15, "time", json_object_new_int(300));
    json_object_object_add(point15, "time_window_start", json_object_new_int(55631));
    json_object_object_add(point15, "time_window_end", json_object_new_int(58516));

    json_object* point16 = json_object_new_object();
    json_object_object_add(point16, "address", json_object_new_string("2135 MCCLOSKEY AVENUE, Louisville, KY, 40210"));
    json_object_object_add(point16, "lng", json_object_new_double(-85.789032));
    json_object_object_add(point16, "lat", json_object_new_double(38.218662));
    json_object_object_add(point16, "is_depot", json_object_new_boolean(FALSE));
    json_object_object_add(point16, "time", json_object_new_int(300));
    json_object_object_add(point16, "time_window_start", json_object_new_int(58516));
    json_object_object_add(point16, "time_window_end", json_object_new_int(61080));

    json_object* point17 = json_object_new_object();
    json_object_object_add(point17, "address", json_object_new_string("1409 PHYLLIS AVE, Louisville, KY, 40215"));
    json_object_object_add(point17, "lng", json_object_new_double(-85.781387));
    json_object_object_add(point17, "lat", json_object_new_double(38.206154));
    json_object_object_add(point17, "is_depot", json_object_new_boolean(FALSE));
    json_object_object_add(point17, "time", json_object_new_int(100));
    json_object_object_add(point17, "time_window_start", json_object_new_int(61080));
    json_object_object_add(point17, "time_window_end", json_object_new_int(61504));

    json_object* point18 = json_object_new_object();
    json_object_object_add(point18, "address", json_object_new_string("4504 SUNFLOWER AVE, Louisville, KY, 40216"));
    json_object_object_add(point18, "lng", json_object_new_double(-85.839149));
    json_object_object_add(point18, "lat", json_object_new_double(38.187511));
    json_object_object_add(point18, "is_depot", json_object_new_boolean(FALSE));
    json_object_object_add(point18, "time", json_object_new_int(300));
    json_object_object_add(point18, "time_window_start", json_object_new_int(61504));
    json_object_object_add(point18, "time_window_end", json_object_new_int(62061));

    json_object* point19 = json_object_new_object();
    json_object_object_add(point19, "address", json_object_new_string("2512 GREENWOOD AVE, Louisville, KY, 40210"));
    json_object_object_add(point19, "lng", json_object_new_double(-85.795059));
    json_object_object_add(point19, "lat", json_object_new_double(38.241405));
    json_object_object_add(point19, "is_depot", json_object_new_boolean(FALSE));
    json_object_object_add(point19, "time", json_object_new_int(300));
    json_object_object_add(point19, "time_window_start", json_object_new_int(62061));
    json_object_object_add(point19, "time_window_end", json_object_new_int(65012));

    json_object* point20 = json_object_new_object();
    json_object_object_add(point20, "address", json_object_new_string("5500 WILKE FARM AVE, Louisville, KY, 40216"));
    json_object_object_add(point20, "lng", json_object_new_double(-85.863319));
    json_object_object_add(point20, "lat", json_object_new_double(38.166065));
    json_object_object_add(point20, "is_depot", json_object_new_boolean(FALSE));
    json_object_object_add(point20, "time", json_object_new_int(300));
    json_object_object_add(point20, "time_window_start", json_object_new_int(65012));
    json_object_object_add(point20, "time_window_end", json_object_new_int(67541));

    json_object* point21 = json_object_new_object();
    json_object_object_add(point21, "address", json_object_new_string("3640 LENTZ AVE, Louisville, KY, 40215"));
    json_object_object_add(point21, "lng", json_object_new_double(-85.786201));
    json_object_object_add(point21, "lat", json_object_new_double(38.193283));
    json_object_object_add(point21, "is_depot", json_object_new_boolean(FALSE));
    json_object_object_add(point21, "time", json_object_new_int(300));
    json_object_object_add(point21, "time_window_start", json_object_new_int(67541));
    json_object_object_add(point21, "time_window_end", json_object_new_int(69120));

    json_object* point22 = json_object_new_object();
    json_object_object_add(point22, "address", json_object_new_string("1020 BLUEGRASS AVE, Louisville, KY, 40215"));
    json_object_object_add(point22, "lng", json_object_new_double(-85.780037));
    json_object_object_add(point22, "lat", json_object_new_double(38.17952));
    json_object_object_add(point22, "is_depot", json_object_new_boolean(FALSE));
    json_object_object_add(point22, "time", json_object_new_int(300));
    json_object_object_add(point22, "time_window_start", json_object_new_int(69120));
    json_object_object_add(point22, "time_window_end", json_object_new_int(70572));

    json_object* point23 = json_object_new_object();
    json_object_object_add(point23, "address", json_object_new_string("123 NORTH 40TH ST, Louisville, KY, 40212"));
    json_object_object_add(point23, "lng", json_object_new_double(-85.814156));
    json_object_object_add(point23, "lat", json_object_new_double(38.26498));
    json_object_object_add(point23, "is_depot", json_object_new_boolean(FALSE));
    json_object_object_add(point23, "time", json_object_new_int(300));
    json_object_object_add(point23, "time_window_start", json_object_new_int(70572));
    json_object_object_add(point23, "time_window_end", json_object_new_int(73177));

    json_object* point24 = json_object_new_object();
    json_object_object_add(point24, "address", json_object_new_string("7315 ST ANDREWS WOODS CIRCLE UNIT 104, Louisville, KY, 40214"));
    json_object_object_add(point24, "lng", json_object_new_double(-85.802867));
    json_object_object_add(point24, "lat", json_object_new_double(38.151072));
    json_object_object_add(point24, "is_depot", json_object_new_boolean(FALSE));
    json_object_object_add(point24, "time", json_object_new_int(300));
    json_object_object_add(point24, "time_window_start", json_object_new_int(73177));
    json_object_object_add(point24, "time_window_end", json_object_new_int(75231));

    json_object* point25 = json_object_new_object();
    json_object_object_add(point25, "address", json_object_new_string("3210 POPLAR VIEW DR, Louisville, KY, 40216"));
    json_object_object_add(point25, "lng", json_object_new_double(-85.849937));
    json_object_object_add(point25, "lat", json_object_new_double(38.182594));
    json_object_object_add(point25, "is_depot", json_object_new_boolean(FALSE));
    json_object_object_add(point25, "time", json_object_new_int(300));
    json_object_object_add(point25, "time_window_start", json_object_new_int(75231));
    json_object_object_add(point25, "time_window_end", json_object_new_int(77663 ));

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

