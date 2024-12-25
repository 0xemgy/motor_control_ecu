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

// Local Defines -------------------------------------------------------------------------------------------------------
// Local Function Prototypes -------------------------------------------------------------------------------------------
// Local Data Types ----------------------------------------------------------------------------------------------------
// Local Variables -----------------------------------------------------------------------------------------------------
// Global Variables ----------------------------------------------------------------------------------------------------
// Local Functions -----------------------------------------------------------------------------------------------------
// Global Functions ----------------------------------------------------------------------------------------------------

void scheduler_config_init(void)
{
    crc_config_init();
}

#include "partition_info.h"

static volatile uint32_t header_crc;
static volatile uint32_t code_crc;
static volatile uint32_t trailer_crc;

void scheduler_config_run_idle(void)
{
    header_crc = crc_config_calculate(CRC_CONFIG_HANDLE_CRC32_ZLIB, &partition_info_header, sizeof(partition_info_header) - 4);
    trailer_crc = crc_config_calculate(CRC_CONFIG_HANDLE_CRC32_ZLIB, &partition_info_trailer, sizeof(partition_info_trailer) - 4);
    code_crc = crc_config_calculate(CRC_CONFIG_HANDLE_CRC32_ZLIB, (void*)partition_info_header.start_address, partition_info_header.code_size);
}
