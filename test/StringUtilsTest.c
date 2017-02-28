
#include <stdarg.h>
#include <setjmp.h>
#include <stddef.h>
#include <cmocka.h>

static int isEmptyTestPositive()
{
    char test[] = "";
    int ret = str_empty(test);
    assert_int_equal(1, ret);

    char* ptest = NULL;
    ret = str_empty(ptest);
    assert_int_equal(1, ret);
}

static int isEmptyTestNegative()
{
    char test[] = "test";
    int ret = str_empty(test);
    assert_int_equal(0, ret);
}

int main(int argc, char** argv)
{
    const struct CMUnitTest tests[] =
    {
        cmocka_unit_test(isEmptyTestNegative),
        cmocka_unit_test(isEmptyTestPositive),
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}

