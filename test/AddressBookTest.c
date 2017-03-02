
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

static int getAllContacts()
{
    struct Limit limit = {5,10};
    int ret = get_all_address_book_contacts(&limit);
    assert_int_equal(0, ret);
    return ret;
}

static int getOneContact()
{
    struct Limit limit = {5,10};
    int ret = get_address_book_by_text("Wall", &limit);
    assert_int_equal(0, ret);
    return ret;
}

int main(int argc, char** argv)
{
    const struct CMUnitTest tests[] =
    {
        cmocka_unit_test(getAllContacts),
        cmocka_unit_test(getOneContact),
    };
    return cmocka_run_group_tests(tests, group_setup, group_teardown);
}

