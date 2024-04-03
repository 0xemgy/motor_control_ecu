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

/**
 * @brief Data in decimal format
 * @details I.e. v1.2.3 = 1, 2, 3
 */
typedef struct util_semver
{
    uint8_t major; /**< Major version */
    uint8_t minor; /**< Minor version */
    uint8_t patch; /**< Patch version */
} util_semver_t;

/**
 * @brief Data in binary coded data format
 * @details I.e. v1.2.3 = 0x01, 0x02, 0x03
 */
typedef struct util_semver_bcd
{
    uint8_t major; /**< Major version */
    uint8_t minor; /**< Minor version */
    uint8_t patch; /**< Patch version */
} util_semver_bcd_t;

// Global Variables ----------------------------------------------------------------------------------------------------
// Global Functions ----------------------------------------------------------------------------------------------------

#endif
