
#include <stdarg.h>
#include <setjmp.h>
#include <stddef.h>
#include <cmocka.h>
#include <route4me.h>

static char key[] = "11111111111111111111111111111111";

static int getZonePositive()
{
    int ret = 0;
    init(key, 1);
    ret = get_avoidance_zone("A1");
    cleanUp();
    assert_int_equal(0, ret);
    return ret;
}

static int getZoneNegative()
{
    int ret = 0;
    init(key, 1);
    ret = get_avoidance_zone("AAA");
    cleanUp();
    assert_int_equal(-1, ret);
    return ret;
}

static int getAllZones()
{
    int ret = 0;
    init(key, 1);
    ret = get_avoidance_zones();
    cleanUp();
    assert_int_equal(0, ret);
    return ret;
}

int main(int argc, char** argv)
{
    const struct CMUnitTest tests[] =
    {
        cmocka_unit_test(getZoneNegative()),
        cmocka_unit_test(getZonePositive()),
        cmocka_unit_test(getAllZones()),
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}

