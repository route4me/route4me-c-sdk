
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

static int getAllOrders()
{
    int ret = get_all_orders();
    assert_int_equal(0, ret);
    return ret;
}

static int getCustomOrders()
{
    struct Limit limit = {0,100};
    int ret = get_custom_orders("order_id,member_id", &limit);
    assert_int_equal(0, ret);
    return ret;
}

int main(int argc, char** argv)
{
    const struct CMUnitTest tests[] =
    {
        cmocka_unit_test(getAllOrders),
        cmocka_unit_test(getCustomOrders),
    };
    return cmocka_run_group_tests(tests, group_setup, group_teardown);
}

