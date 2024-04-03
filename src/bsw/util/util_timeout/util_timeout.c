/**
 * @file util_timeout.c
 * @author 0xemgy (0xemgy@gmail.com)
 * @brief See util_timeout.h
 *
 * @copyright Copyright (c) 2024 0xemgy
 */

// Local Includes ------------------------------------------------------------------------------------------------------

#include "util_timeout.h"

// Local Defines -------------------------------------------------------------------------------------------------------
// Local Function Prototypes -------------------------------------------------------------------------------------------
// Local Data Types ----------------------------------------------------------------------------------------------------
// Local Variables -----------------------------------------------------------------------------------------------------
// Global Variables ----------------------------------------------------------------------------------------------------
// Local Functions -----------------------------------------------------------------------------------------------------
// Global Functions ----------------------------------------------------------------------------------------------------

void util_timeout_init(util_timeout_t *me, const util_timeout_config_t *config)
{
    me->config = config;

    me->timer = me->config->t_timeout;
}

void util_timeout_run(util_timeout_t *me)
{
    if (me->timer >= me->config->t_run_cycle)
    {
        me->timer -= me->config->t_run_cycle;
    }
    else
    {
        me->timer = (uint32_t)0;
    }
}

void util_timeout_restart(util_timeout_t *me)
{
    me->timer = me->config->t_timeout;
}

bool util_timeout_is_timeout(const util_timeout_t *me)
{
    return (me->timer == (uint32_t)0);
}
