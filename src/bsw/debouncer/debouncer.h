/**
 * @file debouncer.h
 * @author 0xemgy (0xemgy@gmail.com)
 * @brief Debouncer
 *
 * @copyright Copyright (c) 2024 0xemgy
 */

#ifndef DEBOUNCER_H
#define DEBOUNCER_H

// Global Includes -----------------------------------------------------------------------------------------------------

#include "timeout.h"
#include "util_getter.h"

#include <stdbool.h>
#include <stdint.h>

// Global Defines ------------------------------------------------------------------------------------------------------

// Global Data Types ---------------------------------------------------------------------------------------------------

typedef bool (*debouncer_get_input_t)(uint32_t handle);

typedef enum debouncer_state
{
    DEBOUNCER_STATE_FALSE,
    DEBOUNCER_STATE_TRUE,
    DEBOUNCER_STATE_MAX
} debouncer_state_t;

typedef struct debouncer_config
{
    timeout_config_t         timeout_config;
    debouncer_state_t        initial_state;
    util_getter_bool_t get_input;
    uint32_t                 t_run_cycle;
} debouncer_config_t;

typedef struct debouncer
{
    const debouncer_config_t *config;
    debouncer_state_t         state;
    timeout_t                 timeout;
} debouncer_t;

// Global Variables ----------------------------------------------------------------------------------------------------
// Global Functions ----------------------------------------------------------------------------------------------------

void              debouncer_init(debouncer_t *me, const debouncer_config_t *config);
void              debouncer_run(debouncer_t *me);
debouncer_state_t debouncer_get_state(const debouncer_t *me);

#endif
