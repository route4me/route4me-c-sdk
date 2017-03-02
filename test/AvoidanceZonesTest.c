
#include <stdarg.h>
#include <setjmp.h>
#include <stddef.h>
#include <cmocka.h>
#include <route4me.h>

static char key[] = "11111111111111111111111111111111";

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

static int getZonePositive()
{
    int ret = get_avoidance_zone("A1");
    assert_int_equal(0, ret);
    return ret;
}

static int getZoneNegative()
{
    int ret = get_avoidance_zone("AAA");
    assert_int_equal(-9, ret);
    return ret;
}

static int getAllZones()
{
    int ret = get_avoidance_zones();
    assert_int_equal(0, ret);
    return ret;
}

int main(int argc, char** argv)
{
    const struct CMUnitTest tests[] =
    {
        cmocka_unit_test(getZoneNegative),
        cmocka_unit_test(getZonePositive),
        cmocka_unit_test(getAllZones),
    };
    return cmocka_run_group_tests(tests, group_setup, group_teardown);
}

