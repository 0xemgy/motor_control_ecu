/**
 * @file scheduler_config.c
 * @author 0xemgy (0xemgy@gmail.com)
 * @brief See scheduler_config.h
 *
 * @copyright Copyright (c) 2024 0xemgy
 */

// Local Includes ------------------------------------------------------------------------------------------------------

#include "scheduler_config.h"

#include "crc_config.h"
#include "partition_info.h"

// Local Defines -------------------------------------------------------------------------------------------------------
// Local Function Prototypes -------------------------------------------------------------------------------------------
// Local Data Types ----------------------------------------------------------------------------------------------------
// Local Variables -----------------------------------------------------------------------------------------------------

static volatile uint32_t scheduler_config_header_crc;  /**< Test variable */
static volatile uint32_t scheduler_config_code_crc;    /**< Test variable */
static volatile uint32_t scheduler_config_trailer_crc; /**< Test variable */

// Global Variables ----------------------------------------------------------------------------------------------------
// Local Functions -----------------------------------------------------------------------------------------------------
// Global Functions ----------------------------------------------------------------------------------------------------

void scheduler_config_init(void)
{
    crc_config_init();
}

void scheduler_config_run_idle(void)
{
    scheduler_config_header_crc =
    crc_config_calculate(CRC_CONFIG_HANDLE_CRC32_ZLIB, &partition_info_header, sizeof(partition_info_header) - (uint32_t)4);
    scheduler_config_trailer_crc = crc_config_calculate(
    CRC_CONFIG_HANDLE_CRC32_ZLIB, &partition_info_trailer, sizeof(partition_info_trailer) - (uint32_t)4);
    scheduler_config_code_crc = crc_config_calculate(
    CRC_CONFIG_HANDLE_CRC32_ZLIB, partition_info_header.start_address, partition_info_header.code_size);
}
