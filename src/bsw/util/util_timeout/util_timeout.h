/**
 * @file timeout.h
 * @author 0xemgy (0xemgy@gmail.com)
 * @brief Timeout
 *
 * @copyright Copyright (c) 2024 0xemgy
 */

#ifndef UTIL_TIMEOUT_H
#define UTIL_TIMEOUT_H

// Global Includes -----------------------------------------------------------------------------------------------------

#include <stdbool.h>
#include <stdint.h>

// Global Defines ------------------------------------------------------------------------------------------------------
// Global Data Types ---------------------------------------------------------------------------------------------------

typedef struct util_timeout_config
{
    uint32_t t_timeout;
    uint32_t t_run_cycle;
} util_timeout_config_t;

typedef struct timeout
{
    const util_timeout_config_t *config;
    uint32_t                     timer;
} util_timeout_t;

// Global Variables ----------------------------------------------------------------------------------------------------
// Global Functions ----------------------------------------------------------------------------------------------------

void util_timeout_init(util_timeout_t *me, const util_timeout_config_t *config);
void util_timeout_run(util_timeout_t *me);
void util_timeout_restart(util_timeout_t *me);
bool util_timeout_is_timeout(const util_timeout_t *me);

#endif
