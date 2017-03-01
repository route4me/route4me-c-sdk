
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

static int reoptimizeTest()
{
    const char id[] = "c46648541ca5d716a31ffae6f405a37d";
    int ret = reoptimize(id);
    assert_int_equal(0, ret);
    return ret;
}

static int getOptimization()
{
    const char id[] = "2FB5F91365317758045DB9F19DF5A522";
    int ret = get_optimization(id);
    assert_int_equal(0, ret);
    return ret;
}

int main(int argc, char** argv)
{
    const struct CMUnitTest tests[] =
    {
        cmocka_unit_test(reoptimizeTest),
        cmocka_unit_test(getOptimization),
    };
    return cmocka_run_group_tests(tests, group_setup, group_teardown);
}

