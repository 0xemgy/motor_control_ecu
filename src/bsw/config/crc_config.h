/**
 * @file crc_config.h
 * @author 0xemgy (0xemgy@gmail.com)
 * @brief Cyclic redundancy check
 *
 * @copyright Copyright (c) 2024 0xemgy
 */

#ifndef CRC_CONFIG_H
#define CRC_CONFIG_H

// Global Includes -----------------------------------------------------------------------------------------------------

#include <stdint.h>

// Global Defines ------------------------------------------------------------------------------------------------------
// Global Data Types ---------------------------------------------------------------------------------------------------

/// CRCs
typedef enum crc_config_handle
{
    CRC_CONFIG_HANDLE_CRC32_ZLIB,
    CRC_CONFIG_HANDLE_MAX,
} crc_config_handle_t;

// Global Variables ----------------------------------------------------------------------------------------------------
// Global Functions ----------------------------------------------------------------------------------------------------

/**
 * @brief Initialize module
 */
void crc_config_init(void);

/**
 * @brief Calculate
 *
 * @param handle Handle
 * @param data Data
 * @param len [Byte] Length
 *
 * @return Result
 */
uint32_t crc_config_calculate(uint32_t handle, const void *data, uint32_t len);

#endif
