
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

static int validateTest()
{
    const char session_id[] = "4552222222";
    const char member_id[] = "787544566";
    int ret = validate_session(session_id, member_id, "XML");
    assert_int_equal(0, ret);
    return ret;
}

int main(int argc, char** argv)
{
    const struct CMUnitTest tests[] =
    {
        cmocka_unit_test(validateTest),
    };
    return cmocka_run_group_tests(tests, group_setup, group_teardown);
}

