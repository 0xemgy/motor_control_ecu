
#include "util.h"
#include "util_mem.h"

#include "version.h"

#include <stdbool.h>
#include <stdint.h>
#include <string.h>

static void unused_test_func(uint8_t foo);

// typedef struct test_struct
// {
//     uint8_t dummy;
// } test_struct_t;

// typedef enum test_enum
// {
//     TEST_ENUM_0,
//     TEST_ENUM_1,
//     TEST_ENUM_MAX
// } test_enum_t;

#define MAGIC_NUMBER_1 ((uint8_t)255)
#define MAGIC_NUMBER_2 ((uint8_t)0x10)
#define MAGIC_NUMBER_3 ((uint8_t)5)
#define MAGIC_NUMBER_4 42LU

int main(void)
{
    volatile uint8_t val = MAGIC_NUMBER_1;

    if ((val == MAGIC_NUMBER_1) && (version.sw_version.major == MAGIC_NUMBER_2))
    {
        val = 4;
    }

    unused_test_func(val); // 3.2 non-compliant comment ends with backslash

    while (1)
    {
    }

    return 0;
}

static const uint8_t bar = 5;

// void misra_2_7_unused_param (int *param1, int unused_param)
// {
//     *param1 = 42U;
// }

static volatile bool test_variable = false;
static uint8_t       main_foo(void);

static void unused_test_func(uint8_t foo)
{
    uint32_t src[MAGIC_NUMBER_3];
    uint32_t dst[MAGIC_NUMBER_3];

    (void)bar;
    (void)test_variable;

    src[0] = 0;
    // src[1] = 1;
    // src[2] = 2;
    // src[3] = 3;
    // src[4] = 4;

    if (foo == main_foo())
    {
        test_variable = foo > (uint8_t)0;
    }
    (void)foo;

    util_mem_memcpy32(dst, src, UTIL_LEN(src));
    (void)memcpy(dst, src, UTIL_LEN(src));
}

static uint8_t main_foo(void)
{
    return MAGIC_NUMBER_4;
}
