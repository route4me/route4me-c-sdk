
#include <stdarg.h>
#include <setjmp.h>
#include <stddef.h>
#include <cmocka.h>
#include <route4me.h>

static char key[] = "11111111111111111111111111111111";

static int getAllContacts()
{
    int ret = 0;
    init(key, 1);
    struct Limit limit = {5,10};
    ret = get_all_address_book_contacts(&limit);
    cleanUp();
    assert_int_equal(0, ret);
    return ret;
}

static int getOneContact()
{
    int ret = 0;
    init(key, 1);
    struct Limit limit = {5,10};
    ret = get_address_book_by_text("Wall", &limit);
    cleanUp();
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
    return cmocka_run_group_tests(tests, NULL, NULL);
}

