/**
 * @file util_mem.h
 * @author 0xemgy (0xemgy@gmail.com)
 * @brief Memory utility functions
 *
 * @copyright Copyright (c) 2024 0xemgy
 */

#ifndef UTIL_MEM_H
#define UTIL_MEM_H

// Global Includes -----------------------------------------------------------------------------------------------------

#include <stdint.h>

// Global Defines ------------------------------------------------------------------------------------------------------
// Global Data Types ---------------------------------------------------------------------------------------------------
// Global Variables ----------------------------------------------------------------------------------------------------
// Global Functions ----------------------------------------------------------------------------------------------------

void util_mem_memcpy32(uint32_t *dst, const uint32_t *src, uint32_t len);
void util_mem_memset32(uint32_t *dst, uint32_t val, uint32_t len);

#endif
