
#include <stdarg.h>
#include <setjmp.h>
#include <stddef.h>
#include <cmocka.h>
#include <route4me.h>

static char key[] = "11111111111111111111111111111111";

static int getAllActivities()
{
    int ret = 0;
    init(key, 1);
    struct Limit limit = {5,10};
    ret = get_all_activities(&limit);
    cleanUp();
    assert_int_equal(0, ret);
    return ret;
}

int main(int argc, char** argv)
{
    const struct CMUnitTest tests[] =
    {
        cmocka_unit_test(getAllActivities()),
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}

