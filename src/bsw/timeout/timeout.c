/**
 * @file timeout.c
 * @author 0xemgy (0xemgy@gmail.com)
 * @brief See timeout.h
 *
 * @copyright Copyright (c) 2024 0xemgy
 */

// Local Includes ------------------------------------------------------------------------------------------------------

#include "timeout.h"

// Local Defines -------------------------------------------------------------------------------------------------------
// Local Function Prototypes -------------------------------------------------------------------------------------------
// Local Data Types ----------------------------------------------------------------------------------------------------
// Local Variables -----------------------------------------------------------------------------------------------------
// Global Variables ----------------------------------------------------------------------------------------------------
// Local Functions -----------------------------------------------------------------------------------------------------
// Global Functions ----------------------------------------------------------------------------------------------------

void timeout_init(timeout_t *me, const timeout_config_t *config)
{
    me->config = config;

    me->timer = me->config->t_timeout;
}

void timeout_run(timeout_t *me)
{
    if(me->timer >= me->config->t_run_cycle)
    {
        me->timer -= me->config->t_run_cycle;
    }
    else
    {
        me->timer = (uint32_t)0;
    }
}

void timeout_restart(timeout_t *me)
{
    me->timer = me->config->t_timeout;
}

bool timeout_is_timeout(const timeout_t *me)
{
    return (me->timer == (uint32_t)0);
}
