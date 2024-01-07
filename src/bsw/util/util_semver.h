/**
 * @file util_semver.h
 * @author 0xemgy (0xemgy@gmail.com)
 * @brief Semantic versioning data types
 *
 * @copyright Copyright (c) 2024 0xemgy
 */

#ifndef UTIL_SEMVER_H
#define UTIL_SEMVER_H

// Global Includes -----------------------------------------------------------------------------------------------------

#include <stdint.h>

// Global Defines ------------------------------------------------------------------------------------------------------
// Global Data Types ---------------------------------------------------------------------------------------------------

typedef struct util_semver
{
    uint8_t major;
    uint8_t minor;
    uint8_t patch;
} util_semver_t;

typedef struct util_semver_bcd
{
    uint8_t major;
    uint8_t minor;
    uint8_t patch;
} util_semver_bcd_t;

// Global Variables ----------------------------------------------------------------------------------------------------
// Global Functions ----------------------------------------------------------------------------------------------------

#endif
