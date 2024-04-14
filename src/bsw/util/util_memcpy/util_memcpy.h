/**
 * @file util_memcpy.h
 * @author 0xemgy (0xemgy@gmail.com)
 * @brief Copy memory function
 *
 * @copyright Copyright (c) 2024 0xemgy
 */

#ifndef UTIL_MEMCPY_H
#define UTIL_MEMCPY_H

// Global Includes -----------------------------------------------------------------------------------------------------

#include <stdint.h>

// Global Defines ------------------------------------------------------------------------------------------------------
// Global Data Types ---------------------------------------------------------------------------------------------------
// Global Variables ----------------------------------------------------------------------------------------------------
// Global Functions ----------------------------------------------------------------------------------------------------

/**
 * @brief Copy memory
 *
 * @param dst Destination
 * @param src Source
 * @param len [byte] Length
 */
void util_memcpy(void *dst, const void *src, uint32_t len);

#endif
