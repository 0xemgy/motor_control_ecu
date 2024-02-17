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

static void util_debouncer_refresh_input(util_debouncer_t *me);
static void util_debouncer_fsm_run(util_debouncer_t *me);

// Local Data Types ----------------------------------------------------------------------------------------------------
// Local Variables -----------------------------------------------------------------------------------------------------
// Global Variables ----------------------------------------------------------------------------------------------------
// Local Functions -----------------------------------------------------------------------------------------------------

static void util_debouncer_refresh_input(util_debouncer_t *me)
{
    if (me->config->get_input.type == UTIL_GETTER_TYPE_DIRECTLY)
    {
        me->input = me->config->get_input.functions.get_directly();
    }
    else
    {
        me->input = me->config->get_input.functions.get_by_handle.get(me->config->get_input.functions.get_by_handle.handle);
    }
}

static void util_debouncer_fsm_run(util_debouncer_t *me)
{
    switch (me->state)
    {
    case UTIL_DEBOUNCER_STATE_FALSE:
        if (!me->input)
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
        if (me->input)
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

// Global Functions ----------------------------------------------------------------------------------------------------

void util_debouncer_init(util_debouncer_t *me, const util_debouncer_config_t *config)
{
    me->config = config;
    me->state  = me->config->initial_state;
    me->input  = (me->config->initial_state == UTIL_DEBOUNCER_STATE_TRUE);

    util_timeout_init(&me->timeout, &me->config->timeout_config);
}

void util_debouncer_run(util_debouncer_t *me)
{
    util_debouncer_refresh_input(me);
    util_timeout_run(&me->timeout);
    util_debouncer_fsm_run(me);
}

util_debouncer_state_t util_debouncer_get_state(const util_debouncer_t *me)
{
    return me->state;
}
