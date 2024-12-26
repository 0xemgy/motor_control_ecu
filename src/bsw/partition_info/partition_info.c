/**
 * @file partition_info.c
 * @author 0xemgy (0xemgy@gmail.com)
 * @brief See partition_info.h
 *
 * @copyright Copyright (c) 2024 0xemgy
 */

// Local Includes ------------------------------------------------------------------------------------------------------

#include "partition_info.h"

// Local Defines -------------------------------------------------------------------------------------------------------
// Local Function Prototypes -------------------------------------------------------------------------------------------
// Local Data Types ----------------------------------------------------------------------------------------------------
// Local Variables -----------------------------------------------------------------------------------------------------
// Global Variables ----------------------------------------------------------------------------------------------------

__attribute__((section(".partition_info_header"))) const partition_info_header_t   partition_info_header;
__attribute__((section(".partition_info_trailer"))) const partition_info_trailer_t partition_info_trailer;

// Local Functions -----------------------------------------------------------------------------------------------------
// Global Functions ----------------------------------------------------------------------------------------------------
