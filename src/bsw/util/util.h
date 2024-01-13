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

#define UTIL_LEN(x)    ((uint32_t)sizeof(x) / (uint32_t)sizeof(x[0]))
#define UTIL_TO_BCD(x) ((uint8_t)(((((uint32_t)x) / (uint32_t)10) << 4) | (((uint32_t)x) % 10)))

// Global Data Types ---------------------------------------------------------------------------------------------------
// Global Variables ----------------------------------------------------------------------------------------------------
// Global Functions ----------------------------------------------------------------------------------------------------

#endif
