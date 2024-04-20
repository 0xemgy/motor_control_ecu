/**
 * @file test_util_memcpy.c
 * @author 0xemgy (0xemgy@gmail.com)
 * @brief Unit test
 *
 * @copyright Copyright (c) 2024 0xemgy
 */

// Local Includes ------------------------------------------------------------------------------------------------------

#include "fff.h"
#include "unity.h"

#include "util_memcpy.h"

// Local Defines -------------------------------------------------------------------------------------------------------

#define N_TEST_VALS ((uint8_t)17) /**< Number of test values */

// Local Function Prototypes -------------------------------------------------------------------------------------------

/**
 * @brief Copy whole source data to destination
 */
static void test_cpy_array_complete(void);

/**
 * @brief Copy all but the last source data to destination
 */
static void test_cpy_array_incomplete(void);

// Local Data Types ----------------------------------------------------------------------------------------------------
// Local Variables -----------------------------------------------------------------------------------------------------

static uint8_t data[N_TEST_VALS];     /**< Destination buffer */
static uint8_t cpy_data[N_TEST_VALS]; /**< Source buffer */

// Global Variables ----------------------------------------------------------------------------------------------------
// Local Functions -----------------------------------------------------------------------------------------------------

static void test_cpy_array_complete(void)
{
    for (uint8_t i = (uint8_t)0; i < N_TEST_VALS; i++)
    {
        TEST_ASSERT_NOT_EQUAL_UINT8(cpy_data[i], data[i]);
    }

    util_memcpy(data, cpy_data, sizeof(data));

    for (uint8_t i = (uint8_t)0; i < N_TEST_VALS; i++)
    {
        TEST_ASSERT_EQUAL_UINT8(cpy_data[i], data[i]);
    }
}

static void test_cpy_array_incomplete(void)
{
    for (uint8_t i = (uint8_t)0; i < N_TEST_VALS; i++)
    {
        TEST_ASSERT_NOT_EQUAL_UINT8(cpy_data[i], data[i]);
    }

    util_memcpy(data, cpy_data, sizeof(data) - 1);

    for (uint8_t i = (uint8_t)0; i < (N_TEST_VALS - (uint8_t)1); i++)
    {
        TEST_ASSERT_EQUAL_UINT8(cpy_data[i], data[i]);
    }

    TEST_ASSERT_NOT_EQUAL_UINT8(cpy_data[sizeof(data) - 1], data[sizeof(data) - 1]);
}

// Global Functions ----------------------------------------------------------------------------------------------------

void setUp(void)
{
    for (uint8_t i = (uint8_t)0; i < N_TEST_VALS; i++)
    {
        data[i]     = (uint8_t)0;
        cpy_data[i] = (i + (uint8_t)1);
    }
}

void tearDown(void)
{
}

int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_cpy_array_complete);
    RUN_TEST(test_cpy_array_incomplete);

    return UNITY_END();
}
