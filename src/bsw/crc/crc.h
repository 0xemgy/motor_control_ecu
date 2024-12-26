/**
 * @file crc.h
 * @author 0xemgy (0xemgy@gmail.com)
 * @brief Cyclic redundancy check
 *
 * @copyright Copyright (c) 2024 0xemgy
 */

#ifndef CRC_H
#define CRC_H

// Global Includes -----------------------------------------------------------------------------------------------------

#include <stdbool.h>
#include <stdint.h>

// Global Defines ------------------------------------------------------------------------------------------------------
// Global Data Types ---------------------------------------------------------------------------------------------------

/// CRC polynomial sizes
typedef enum crc_poly_size
{
    CRC_POLY_SIZE_32,
    CRC_POLY_SIZE_16,
    CRC_POLY_SIZE_8,
    CRC_POLY_SIZE_MAX
} crc_poly_size_t;

/// Module configuration data
typedef struct crc_config
{
    crc_poly_size_t poly_size; ///< Polynomial size
    uint32_t        poly;      ///< Polynomial
    uint32_t        init;      ///< Initial value
    bool            ref_in;    ///< Reverse input data bit order
    bool            ref_out;   ///< Reverse output data bit order
    uint32_t        xor_out;   ///< Invert final result
    uint32_t        check;     ///< Check value
} crc_config_t;

/// Module instance data
typedef struct crc
{
    const crc_config_t *config; ///< Configuration data
    uint32_t            result; ///< Result
} crc_t;

// Global Variables ----------------------------------------------------------------------------------------------------
// Global Functions ----------------------------------------------------------------------------------------------------

/**
 * @brief Initialize module
 *
 * @param me Module instance
 * @param config Module configuration data
 */
void crc_init(crc_t *me, const crc_config_t *config);

/**
 * @brief Calculate
 *
 * @param me Module instance
 * @param data Data
 * @param len [Byte] Length
 *
 * @return Result
 */
uint32_t crc_calculate(crc_t *me, const void *data, uint32_t len);

/**
 * @brief Get result
 *
 * @param me Module instance
 *
 * @return Result
 */
uint32_t crc_get_result(const crc_t *me);

#endif
