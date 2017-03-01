
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

static int getRouteNotes()
{
    const char route_id[] = "CA902292134DBC134EAF8363426BD247";
    const char route_destination_id[] = "174405709A";

    int ret = get_route_notes(route_id, route_destination_id);
    assert_int_equal(0, ret);
    return ret;
}

int main(int argc, char** argv)
{
    const struct CMUnitTest tests[] =
    {
        cmocka_unit_test(getRouteNotes),
    };
    return cmocka_run_group_tests(tests, group_setup, group_teardown);
}

