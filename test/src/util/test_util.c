#include "unity.h"

#include "util.h"

void test_memcpy32(void)
{
    uint32_t test_data[4] = {0x12345678, 0x9ABCDEF0, 0xAABBCCDD, 0x11223344};
    uint32_t copied_data[4] = {0};

    util_memcpy32(copied_data, test_data, UTIL_LEN(test_data));

    for(uint32_t i = 0; i < UTIL_LEN(test_data); i++)
    {
        TEST_ASSERT_EQUAL_UINT32(test_data[i], copied_data[i]);
    }
}

void setUp(void)
{

}

void tearDown(void)
{

}

int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_memcpy32);

    return UNITY_END();
}
