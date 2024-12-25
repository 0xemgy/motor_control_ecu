/**
 * @file crc.c
 * @author 0xemgy (0xemgy@gmail.com)
 * @brief See crc.h
 *
 * @copyright Copyright (c) 2024 0xemgy
 */

// Local Includes ------------------------------------------------------------------------------------------------------

#include "crc.h"

#include "stm32g431xx.h"

#include "util.h"

#include <assert.h>
#include <stddef.h>

// Local Defines -------------------------------------------------------------------------------------------------------
// Local Function Prototypes -------------------------------------------------------------------------------------------
// Local Data Types ----------------------------------------------------------------------------------------------------
// Local Variables -----------------------------------------------------------------------------------------------------

/// Standard test sequence which must result in the check value
static const uint8_t crc_standard_test_sequence[] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };

// Global Variables ----------------------------------------------------------------------------------------------------
// Local Functions -----------------------------------------------------------------------------------------------------
// Global Functions ----------------------------------------------------------------------------------------------------

void crc_init(crc_t *me, const crc_config_t *config)
{
    assert(me != NULL);
    assert(config != NULL);

    me->config = config;

    uint32_t check = crc_calculate(me, crc_standard_test_sequence, UTIL_LEN(crc_standard_test_sequence));
    assert(check == me->config->check);
}

uint32_t crc_calculate(crc_t *me, const void *data, uint32_t len)
{
    assert(me != NULL);
    assert(me->config != NULL);
    assert(data != NULL);
    assert(len > (uint32_t)0);

    CRC->POL  = me->config->poly;
    CRC->INIT = me->config->init;
    CRC->CR = ((((uint32_t)me->config->ref_out) << CRC_CR_REV_OUT_Pos) | (((uint32_t)me->config->ref_in) << CRC_CR_REV_IN_Pos) |
               (((uint32_t)me->config->poly_size) << CRC_CR_POLYSIZE_Pos));
    CRC->CR |= CRC_CR_RESET;

    for (uint32_t i = (uint32_t)0; i < len; i++)
    {
        *(__IO uint8_t *)&CRC->DR = ((const uint8_t *)data)[i];
    }

    me->result = CRC->DR ^ me->config->xor_out;

    return me->result;
}

uint32_t crc_get_result(const crc_t *me)
{
    return me->result;
}
