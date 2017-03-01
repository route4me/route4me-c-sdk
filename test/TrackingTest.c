
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

static int assetTrackingPositive()
{
    const char id[] = "Q7G9P1L9";
    int ret = asset_tracking(id);
    assert_int_equal(0, ret);
    return ret;
}

static int assetTrackingNegative()
{
    const char id[] = "fake";
    int ret = asset_tracking(id);
    assert_int_equal(-1, ret);
    return ret;
}

int main(int argc, char** argv)
{
    const struct CMUnitTest tests[] =
    {
        cmocka_unit_test(assetTrackingPositive),
        cmocka_unit_test(assetTrackingNegative),
    };
    return cmocka_run_group_tests(tests, group_setup, group_teardown);
}

