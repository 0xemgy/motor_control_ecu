/**
 * @file main.c
 * @author 0xemgy (0xemgy@gmail.com)
 * @brief Main function
 *
 * @copyright Copyright (c) 2024 0xemgy
 */

// Local Includes ------------------------------------------------------------------------------------------------------

#include "util.h"
#include "util_memcpy.h"

#include "version.h"

#include <stdbool.h>
#include <stdint.h>
// #include <string.h>

// Local Defines -------------------------------------------------------------------------------------------------------

#define MAGIC_NUMBER_1         ((uint8_t)255)  /**< Magic number */
#define MAGIC_NUMBER_2         ((uint8_t)0x10) /**< Magic number */
#define MAGIC_NUMBER_3         ((uint8_t)50)   /**< Magic number */
#define MAGIC_NUMBER_4         42LU            /**< Magic number */
#define FOO_MACRO_FUNC(X)      (void)X         /**< Macro test function */
#define main_FOO_MACRO_FUNC(X) (void)X         /**< Macro test function */
#define MAIN_FOO_MACRO_FUNC(X) (void)X         /**< Macro test function */

// Local Function Prototypes -------------------------------------------------------------------------------------------

/**
 * @brief Foo
 *
 * @return bar
 */
static uint8_t main_foo(void);

/**
 * @brief bar
 *
 * @param foo foo
 */
static void unused_test_func(uint8_t param1, uint8_t param2, uint8_t param3);

// Local Data Types ----------------------------------------------------------------------------------------------------

typedef struct test_struct
{
    uint8_t member1;
    uint8_t member2;
    uint8_t member3;
} __attribute__((packed, aligned(4))) test_struct_t;

typedef enum test_enum
{
    TET_ENUM_0,
    TEST_ENUM_1,
    TEST_ENUM_MAX
} test_enum_t;

typedef test_enum_t        dudeldu_t;
typedef struct test_struct dudeldi_t;

// Local Variables -----------------------------------------------------------------------------------------------------

static volatile float MAIN_aaa_BBBB = 1.0F;  /**< Dummy variable */
static volatile float main_foo_bar  = 1.0F;  /**< Dummy variable */
static volatile float aaa           = 1.0F;  /**< Dummy variable */
static volatile float bbb;                   /**< Dummy variable */
static volatile float ccc;                   /**< Dummy variable */
static const uint8_t  bar           = 5;     /**< Dummy variable */
static volatile bool  test_variable = false; /**< Dummy variable */
static uint32_t       src[MAGIC_NUMBER_3];   /**< Dummy variable */
static uint32_t       dst[MAGIC_NUMBER_3];   /**< Dummy variable */

// Global Variables ----------------------------------------------------------------------------------------------------

uint8_t global_variable; /**< Foo bar */

// Local Functions -----------------------------------------------------------------------------------------------------

// void misra_2_7_unused_param (int *param1, int unused_param)
// {
//     *param1 = 42U;
// }

static void unused_test_func(uint8_t param1, uint8_t param2, uint8_t param3)
{
    (void)param1;
    (void)param2;
    (void)param3;
    (void)bar;
    (void)test_variable;

    src[0] = 0;
    // src[1] = 1;
    // src[2] = 2;
    // src[3] = 3;
    // src[4] = 4;

    if (main_foo_bar == main_foo())
    {
        // test_variable = foo > (uint8_t)0;
    }
    (void)main_foo_bar;

    util_memcpy(dst, src, UTIL_LEN(src));
    // (void)memcpy(dst, src, sizeof(src));
    // (void)memset(dst, 0, sizeof(dst));

    // (void)dst;
}

static uint8_t main_foo(void)
{
    return MAGIC_NUMBER_4;
}

// Global Functions ----------------------------------------------------------------------------------------------------

extern uint8_t dudelduhihi;

/**
 * @brief Main function
 *
 * @return 0
 */
int main(void)
{
    volatile uint8_t val  = MAGIC_NUMBER_1;
    static uint8_t   val2 = MAGIC_NUMBER_1;
    (void)val2;

    ccc = aaa * bbb;

    (void)ccc;

    if ((val == MAGIC_NUMBER_1) && (version.sw_version.major == MAGIC_NUMBER_2))
    {
        uint8_t val3 = MAGIC_NUMBER_1;
         (void)val3;
        val          = 4;
    }

    unused_test_func(val, val, val); // 3.2 non-compliant comment ends with backslash

    while (1)
    {
    }

    for (;;)
    {
    }

    return 0;
}
