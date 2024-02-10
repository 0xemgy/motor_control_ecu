/**
 * @file util_debouncer.h
 * @author 0xemgy (0xemgy@gmail.com)
 * @brief Debouncer
 *
 * @copyright Copyright (c) 2024 0xemgy
 */

#ifndef UTIL_DEBOUNCER_H
#define UTIL_DEBOUNCER_H

// Global Includes -----------------------------------------------------------------------------------------------------

#include "util_timeout.h"
#include "util_getter.h"

#include <stdbool.h>
#include <stdint.h>

// Global Defines ------------------------------------------------------------------------------------------------------

// Global Data Types ---------------------------------------------------------------------------------------------------

typedef enum util_debouncer_state
{
    UTIL_DEBOUNCER_STATE_FALSE,
    UTIL_DEBOUNCER_STATE_TRUE,
    UTIL_DEBOUNCER_STATE_MAX
} util_debouncer_state_t;

typedef struct util_debouncer_config
{
    util_timeout_config_t  timeout_config;
    util_debouncer_state_t initial_state;
    util_getter_bool_t     get_input;
    uint32_t               t_run_cycle;
} util_debouncer_config_t;

typedef struct util_debouncer
{
    const util_debouncer_config_t *config;
    util_debouncer_state_t         state;
    util_timeout_t                 timeout;
} util_debouncer_t;

// Global Variables ----------------------------------------------------------------------------------------------------
// Global Functions ----------------------------------------------------------------------------------------------------

void                   util_debouncer_init(util_debouncer_t *me, const util_debouncer_config_t *config);
void                   util_debouncer_run(util_debouncer_t *me);
util_debouncer_state_t util_debouncer_get_state(const util_debouncer_t *me);

#endif
