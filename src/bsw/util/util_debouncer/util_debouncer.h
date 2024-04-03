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

#include "util_getter.h"
#include "util_timeout.h"

#include <stdbool.h>
#include <stdint.h>

// Global Defines ------------------------------------------------------------------------------------------------------

// Global Data Types ---------------------------------------------------------------------------------------------------

/**
 * @brief Module state
 */
typedef enum util_debouncer_state
{
    UTIL_DEBOUNCER_STATE_FALSE,
    UTIL_DEBOUNCER_STATE_TRUE,
    UTIL_DEBOUNCER_STATE_MAX
} util_debouncer_state_t;

/**
 * @brief Module configuration
 */
typedef struct util_debouncer_config
{
    util_timeout_config_t  timeout_config; /**< Timeout configuration */
    util_debouncer_state_t initial_state;  /**< Initial state */
    util_getter_bool_t     get_input;      /**< Get input function */
    uint32_t               t_run_cycle;    /**< [ms] Run cycle */
} util_debouncer_config_t;

/**
 * @brief Module instance
 */
typedef struct util_debouncer
{
    const util_debouncer_config_t *config;  /**< Configuration */
    util_debouncer_state_t         state;   /**< State */
    bool                           input;   /**< Input */
    util_timeout_t                 timeout; /**< Timeout */
} util_debouncer_t;

// Global Variables ----------------------------------------------------------------------------------------------------
// Global Functions ----------------------------------------------------------------------------------------------------

/**
 * @brief Initialize module
 *
 * @param me Module instance
 * @param config Module instance configuration
 */
void util_debouncer_init(util_debouncer_t *me, const util_debouncer_config_t *config);

/**
 * @brief Execute module logic
 *
 * @param me Module instance
 */
void util_debouncer_run(util_debouncer_t *me);

/**
 * @brief Get module state
 *
 * @param me Module instance
 * @return Module state
 */
util_debouncer_state_t util_debouncer_get_state(const util_debouncer_t *me);

#endif
