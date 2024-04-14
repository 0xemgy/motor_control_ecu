/**
 * @file util_memset.h
 * @author 0xemgy (0xemgy@gmail.com)
 * @brief Set memory function
 *
 * @copyright Copyright (c) 2024 0xemgy
 */

#ifndef UTIL_MEMSET_H
#define UTIL_MEMSET_H

// Global Includes -----------------------------------------------------------------------------------------------------

#include <stdint.h>

// Global Defines ------------------------------------------------------------------------------------------------------
// Global Data Types ---------------------------------------------------------------------------------------------------
// Global Variables ----------------------------------------------------------------------------------------------------
// Global Functions ----------------------------------------------------------------------------------------------------

/**
 * @brief Set memory
 *
 * @param dst Destination
 * @param val Value to set
 * @param len [byte] Length
 */
void util_memset(void *dst, uint8_t val, uint32_t len);

#endif
