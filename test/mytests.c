#include </home/opently/chessviz-Opently/thirdparty/ctest.h>
#include </home/opently/chessviz-Opently/src/libchessviz/check_move.h>

CTEST(ctest, write1)
{
    const int result = check_move("e2-e4 e7-5e");
    const int expected = 1;
    ASSERT_EQUAL(expected, result);
}

CTEST(ctest, write2)
{
    const int result = check_move("e2-e4 e7-e5");
    const int expected = 0;
    ASSERT_EQUAL(expected, result);
}
