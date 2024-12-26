/**
 * @file crc_config.c
 * @author 0xemgy (0xemgy@gmail.com)
 * @brief See crc_config.h
 *
 * @copyright Copyright (c) 2024 0xemgy
 */

// Local Includes ------------------------------------------------------------------------------------------------------

#include "crc_config.h"

#include "crc.h"

#include "stm32g431xx.h"

#include <assert.h>

// Local Defines -------------------------------------------------------------------------------------------------------
// Local Function Prototypes -------------------------------------------------------------------------------------------
// Local Data Types ----------------------------------------------------------------------------------------------------
// Local Variables -----------------------------------------------------------------------------------------------------

/**
 * @brief Module configurations
 */
static const crc_config_t crc_config_configs[CRC_CONFIG_HANDLE_MAX] = {
    [CRC_CONFIG_HANDLE_CRC32_ZLIB] = {
    .poly_size = CRC_POLY_SIZE_32,
    .poly      = 0x04C11DB7,
    .init      = 0xFFFFFFFFu,
    .ref_in    = true,
    .ref_out   = true,
    .xor_out   = 0xFFFFFFFFu,
    .check     = 0xCBF43926u,
    },
};

/**
 * @brief Module instances
 */
static crc_t crc_config_crcs[CRC_CONFIG_HANDLE_MAX];

// Global Variables ----------------------------------------------------------------------------------------------------
// Local Functions -----------------------------------------------------------------------------------------------------
// Global Functions ----------------------------------------------------------------------------------------------------

void crc_config_init(void)
{
    RCC->AHB1ENR = RCC_AHB1ENR_CRCEN;

    for (uint32_t i = 0; i < (uint32_t)CRC_CONFIG_HANDLE_MAX; i++)
    {
        crc_init(&crc_config_crcs[i], &crc_config_configs[i]);
    }
}

uint32_t crc_config_calculate(uint32_t handle, const void *data, uint32_t len)
{
    assert(handle < (uint32_t)CRC_CONFIG_HANDLE_MAX);

    return crc_calculate(&crc_config_crcs[handle], data, len);
}
