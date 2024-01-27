/**
 * @file debouncer.c
 * @author 0xemgy (0xemgy@gmail.com)
 * @brief See debouncer.h
 *
 * @copyright Copyright (c) 2024 0xemgy
 */

// Local Includes ------------------------------------------------------------------------------------------------------

#include "debouncer.h"

// Local Defines -------------------------------------------------------------------------------------------------------
// Local Function Prototypes -------------------------------------------------------------------------------------------
// Local Data Types ----------------------------------------------------------------------------------------------------
// Local Variables -----------------------------------------------------------------------------------------------------
// Global Variables ----------------------------------------------------------------------------------------------------
// Local Functions -----------------------------------------------------------------------------------------------------
// Global Functions ----------------------------------------------------------------------------------------------------

void debouncer_init(debouncer_t *me, const debouncer_config_t *config)
{
    me->config = config;

    me->state = me->config->initial_state;

    timeout_init(&me->timeout, &me->config->timeout_config);
}

void debouncer_run(debouncer_t *me)
{
    bool input;

    if (me->config->get_input.type == UTIL_GETTER_TYPE_DIRECTLY)
    {
        input = me->config->get_input.functions.get_directly();
    }
    else
    {
        input = me->config->get_input.functions.get_by_handle.get(me->config->get_input.functions.get_by_handle.handle);
    }

    timeout_run(&me->timeout);

    switch (me->state)
    {
    case DEBOUNCER_STATE_FALSE:
        if (!input)
        {
            timeout_restart(&me->timeout);
        }
        else
        {
            if (timeout_is_timeout(&me->timeout))
            {
                me->state = DEBOUNCER_STATE_TRUE;
            }
        }

        break;
    case DEBOUNCER_STATE_TRUE:
        if (input)
        {
            timeout_restart(&me->timeout);
        }
        else
        {
            if (timeout_is_timeout(&me->timeout))
            {
                me->state = DEBOUNCER_STATE_FALSE;
            }
        }
        break;

    default:
        break;
    }
}

debouncer_state_t debouncer_get_state(const debouncer_t *me)
{
    return me->state;
}
