/**
 * @file timeout.h
 * @author 0xemgy (0xemgy@gmail.com)
 * @brief Timeout
 *
 * @copyright Copyright (c) 2024 0xemgy
 */

#ifndef TIMEOUT_H
#define TIMEOUT_H

// Global Includes -----------------------------------------------------------------------------------------------------

#include <stdbool.h>
#include <stdint.h>

// Global Defines ------------------------------------------------------------------------------------------------------
// Global Data Types ---------------------------------------------------------------------------------------------------

typedef struct timeout_config
{
    uint32_t t_timeout;
    uint32_t t_run_cycle;
} timeout_config_t;

typedef struct timeout
{
    const timeout_config_t *config;
    uint32_t timer;
} timeout_t;

// Global Variables ----------------------------------------------------------------------------------------------------
// Global Functions ----------------------------------------------------------------------------------------------------

void timeout_init(timeout_t *me, const timeout_config_t *config);
void timeout_run(timeout_t *me);
void timeout_restart(timeout_t *me);
bool timeout_is_timeout(const timeout_t *me);

#endif
