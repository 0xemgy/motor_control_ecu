/**
 * @file util_debouncer.c
 * @author 0xemgy (0xemgy@gmail.com)
 * @brief See util_debouncer.h
 *
 * @copyright Copyright (c) 2024 0xemgy
 */

// Local Includes ------------------------------------------------------------------------------------------------------

#include "util_debouncer.h"

// Local Defines -------------------------------------------------------------------------------------------------------
// Local Function Prototypes -------------------------------------------------------------------------------------------
// Local Data Types ----------------------------------------------------------------------------------------------------
// Local Variables -----------------------------------------------------------------------------------------------------
// Global Variables ----------------------------------------------------------------------------------------------------
// Local Functions -----------------------------------------------------------------------------------------------------
// Global Functions ----------------------------------------------------------------------------------------------------

void util_debouncer_init(util_debouncer_t *me, const util_debouncer_config_t *config)
{
    me->config = config;

    me->state = me->config->initial_state;

    util_timeout_init(&me->timeout, &me->config->timeout_config);
}

void util_debouncer_run(util_debouncer_t *me)
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

    util_timeout_run(&me->timeout);

    switch (me->state)
    {
    case UTIL_DEBOUNCER_STATE_FALSE:
        if (!input)
        {
            util_timeout_restart(&me->timeout);
        }
        else
        {
            if (util_timeout_is_timeout(&me->timeout))
            {
                me->state = UTIL_DEBOUNCER_STATE_TRUE;
            }
        }

        break;
    case UTIL_DEBOUNCER_STATE_TRUE:
        if (input)
        {
            util_timeout_restart(&me->timeout);
        }
        else
        {
            if (util_timeout_is_timeout(&me->timeout))
            {
                me->state = UTIL_DEBOUNCER_STATE_FALSE;
            }
        }
        break;

    default:
        break;
    }
}

util_debouncer_state_t util_debouncer_get_state(const util_debouncer_t *me)
{
    return me->state;
}
