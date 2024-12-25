/**
 * @file scheduler_config.h
 * @author 0xemgy (0xemgy@gmail.com)
 * @brief Scheduler
 *
 * @copyright Copyright (c) 2024 0xemgy
 */

#ifndef SCHEDULER_CONFIG_H
#define SCHEDULER_CONFIG_H

// Global Includes -----------------------------------------------------------------------------------------------------
// Global Defines ------------------------------------------------------------------------------------------------------
// Global Data Types ---------------------------------------------------------------------------------------------------
// Global Variables ----------------------------------------------------------------------------------------------------
// Global Functions ----------------------------------------------------------------------------------------------------

/**
 * @brief Initialize module
 */
void scheduler_config_init(void);

/**
 * @brief Execute module logic in idle context
 */
void scheduler_config_run_idle(void);

#endif
