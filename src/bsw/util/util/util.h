/**
 * @file util.h
 * @author 0xemgy (0xemgy@gmail.com)
 * @brief Utility functions and macros
 *
 * @copyright Copyright (c) 2024 0xemgy
 */

#ifndef UTIL_H
#define UTIL_H

// Global Includes -----------------------------------------------------------------------------------------------------

#include <stdint.h>

// Global Defines ------------------------------------------------------------------------------------------------------

/**
 * @brief Calculate length of an array
 *
 * @param X Array
 *
 * @return [byte] Length of array
 */
#define UTIL_LEN(X) ((uint32_t)sizeof((X)) / (uint32_t)sizeof((X)[0]))

/**
 * @brief Convert decimal value to BCD value
 *
 * @param X Decimal value
 *
 * @return BCD value
 */
#define UTIL_TO_BCD(X) ((uint8_t)(((((uint32_t)(X)) / (uint32_t)(10)) << 4) | (((uint32_t)(X)) % 10)))

// Global Data Types ---------------------------------------------------------------------------------------------------
// Global Variables ----------------------------------------------------------------------------------------------------
// Global Functions ----------------------------------------------------------------------------------------------------

#endif
