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

#define UTIL_TIMESTAMP_BASE_YEAR ((uint32_t)2000) /**< Base year */

/**
 * @brief Convert decimal year to BCD year
 *
 * @param YEAR_DECIMAL Decimal year
 *
 * @return BCD year
 */
#define UTIL_TIMESTAMP_YEAR_TO_BCD(YEAR_DECIMAL) ((uint8_t)UTIL_TO_BCD(((YEAR_DECIMAL)-UTIL_TIMESTAMP_BASE_YEAR)))

// Global Data Types ---------------------------------------------------------------------------------------------------

/**
 * @brief Data in decimal format
 */
typedef struct util_timestamp
{
    uint16_t year;   /**< Year [0...UINT16_MAX] */
    uint8_t  month;  /**< Month [1...12] */
    uint8_t  day;    /**< Day [1...31] */
    uint8_t  hour;   /**< Hour [0...23] */
    uint8_t  minute; /**< Minute [0...59] */
    uint8_t  second; /**< Second [0...59]*/
} util_timestamp_t;

/**
 * @brief Data in binary coded data format
 */
typedef struct util_timestamp_bcd
{
    uint8_t year;   /**< Year (see UTIL_TIMESTAMP_BASE_YEAR for base year) [0x00...0x99] */
    uint8_t month;  /**< Month [0x01...0x12] */
    uint8_t day;    /**< Day [0x01...0x31] */
    uint8_t hour;   /**< Hour [0x00...0x23] */
    uint8_t minute; /**< Minute [0x00...0x59] */
    uint8_t second; /**< Second [0x00...0x5])*/
} util_timestamp_bcd_t;

// Global Variables ----------------------------------------------------------------------------------------------------
// Global Functions ----------------------------------------------------------------------------------------------------

#endif
