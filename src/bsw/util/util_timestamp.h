/**
 * @file util_timestamp.h
 * @author 0xemgy (0xemgy@gmail.com)
 * @brief Timestamp data types
 *
 * @copyright Copyright (c) 2024 0xemgy
 */

#ifndef UTIL_TIMESTAMP_H
#define UTIL_TIMESTAMP_H

// Global Includes -----------------------------------------------------------------------------------------------------

#include "util.h"

#include <stdint.h>

// Global Defines ------------------------------------------------------------------------------------------------------

#define UTIL_TIMESTAMP_BASE_YEAR ((uint32_t)2000)
#define UTIL_TIMESTAMP_YEAR_TO_BCD(year_decimal) ((uint8_t)UTIL_TO_BCD((year_decimal - UTIL_TIMESTAMP_BASE_YEAR)))

// Global Data Types ---------------------------------------------------------------------------------------------------

typedef struct util_timestamp
{
    uint16_t year;
    uint8_t month;
    uint8_t day;
    uint8_t hour;
    uint8_t minute;
    uint8_t second;
} util_timestamp_t;

typedef struct util_timestamp_bcd
{
    uint8_t year;
    uint8_t month;
    uint8_t day;
    uint8_t hour;
    uint8_t minute;
    uint8_t second;
} util_timestamp_bcd_t;

// Global Variables ----------------------------------------------------------------------------------------------------
// Global Functions ----------------------------------------------------------------------------------------------------

#endif
