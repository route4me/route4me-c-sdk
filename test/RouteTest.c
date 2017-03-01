
#include <stdarg.h>
#include <setjmp.h>
#include <stddef.h>
#include <cmocka.h>
#include <route4me.h>

static char key[] = "11111111111111111111111111111111";
const char route_id[] = "CA902292134DBC134EAF8363426BD247";

static int group_setup()
{
    init(key, 1);
    return 0;
}

static int group_teardown()
{
    cleanUp();
    return 0;
}

static int getRouteByDirections()
{
    int ret = get_route_directions(route_id, 1);
    assert_int_equal(0, ret);
    return ret;
}

static int getRouteByPathPoints()
{
    int ret = get_route_path_points(route_id, "Points");
    assert_int_equal(0, ret);
    return ret;
}

static int getRouteById()
{
    int ret = get_route_path_points(route_id, "Points");
    assert_int_equal(0, ret);
    return ret;
}

static int getMultipleRoutes()
{
    int ret = get_multiple_routes();
    assert_int_equal(0, ret);
    return ret;
}

int main(int argc, char** argv)
{
    const struct CMUnitTest tests[] =
    {
        cmocka_unit_test(getRouteById),
        cmocka_unit_test(getRouteByDirections),
        cmocka_unit_test(getRouteByPathPoints),
        cmocka_unit_test(getMultipleRoutes),
    };
    return cmocka_run_group_tests(tests, group_setup, group_teardown);
}

