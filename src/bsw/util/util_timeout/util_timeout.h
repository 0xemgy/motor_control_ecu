/**
 * @file util_timeout.h
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

/**
 * @brief Module configuration
 */
typedef struct util_timeout_config
{
    uint32_t t_timeout;   /**< [ms] Timeout */
    uint32_t t_run_cycle; /**< [ms] Run cycle */
} util_timeout_config_t;

/**
 * @brief Module instance
 */
typedef struct util_timeout
{
    const util_timeout_config_t *config; /**< Configuration*/
    uint32_t                     timer;  /**< [ms] Timer */
} util_timeout_t;

// Global Variables ----------------------------------------------------------------------------------------------------
// Global Functions ----------------------------------------------------------------------------------------------------

/**
 * @brief Initialize module
 *
 * @param me Module instance
 * @param config Module instance configuration
 */
void util_timeout_init(util_timeout_t *me, const util_timeout_config_t *config);

/**
 * @brief Execute module logic
 *
 * @param me Module instance
 */
void util_timeout_run(util_timeout_t *me);

/**
 * @brief Restart timeout
 *
 * @param me Module instance
 */
void util_timeout_restart(util_timeout_t *me);

/**
 * @brief Check if timeout has elapsed
 *
 * @param me Module instance
 *
 * @retval true Timeout has elapsed
 * @retval false Timeout has not elapsed
 */
bool util_timeout_is_timeout(const util_timeout_t *me);

#endif
