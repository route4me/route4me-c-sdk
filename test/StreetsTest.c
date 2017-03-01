
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

static int getAllStreets()
{
    struct Limit limit = {10,6};
    int ret = get_all_streets(&limit);
    assert_int_equal(0, ret);
    return ret;
}

static int getOneStreet()
{
    int seqno = 1;
    int ret = get_street_address(seqno);
    assert_int_equal(0, ret);
    return ret;
}

int main(int argc, char** argv)
{
    const struct CMUnitTest tests[] =
    {
        cmocka_unit_test(getAllStreets),
        cmocka_unit_test(getOneStreet),
    };
    return cmocka_run_group_tests(tests, group_setup, group_teardown);
}

