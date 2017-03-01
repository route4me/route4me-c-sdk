
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

static int batchGeocoding()
{
    const char addrs[] = "Los20%Angeles20%International20%Airport,20%CA";
    const char format[] = "json";
    int ret = batch_geocoding(addrs, format);
    assert_int_equal(0, ret);
    return ret;
}

static int reverseGeocoding()
{
    const char addrs[] = "33.945705,-118.391105";
    const char format[] = "json";
    int ret = reverse_geocoding(addrs, format);
    assert_int_equal(0, ret);
    return ret;
}

int main(int argc, char** argv)
{
    const struct CMUnitTest tests[] =
    {
        cmocka_unit_test(batchGeocoding),
        cmocka_unit_test(reverseGeocoding),
    };
    return cmocka_run_group_tests(tests, group_setup, group_teardown);
}

