/**
 * @file version.c
 * @author 0xemgy (0xemgy@gmail.com)
 * @brief See version.h
 *
 * @copyright Copyright (c) 2024 0xemgy
 */

// Local Includes ------------------------------------------------------------------------------------------------------

#include "version.h"

#include "version_config.h"

// Local Defines -------------------------------------------------------------------------------------------------------
// Local Function Prototypes -------------------------------------------------------------------------------------------
// Local Data Types ----------------------------------------------------------------------------------------------------
// Local Variables -----------------------------------------------------------------------------------------------------
// Global Variables ----------------------------------------------------------------------------------------------------

const version_t version __attribute__((section(".version"))) =
{
    .project_name = VERSION_CONFIG_PROJECT_NAME,
    .sw_version =
    {
        .major = VERSION_CONFIG_SW_VERSION_MAJOR,
        .minor = VERSION_CONFIG_SW_VERSION_MINOR,
        .patch = VERSION_CONFIG_SW_VERSION_PATCH,
    },
    .build_info =
    {
        .timestamp  =
        {
            .year   = VERSION_CONFIG_BUILD_INFO_TIMESTAMP_YEAR,
            .month  = VERSION_CONFIG_BUILD_INFO_TIMESTAMP_MONTH,
            .day    = VERSION_CONFIG_BUILD_INFO_TIMESTAMP_DAY,
            .hour   = VERSION_CONFIG_BUILD_INFO_TIMESTAMP_HOUR,
            .minute = VERSION_CONFIG_BUILD_INFO_TIMESTAMP_MINUTE,
            .second = VERSION_CONFIG_BUILD_INFO_TIMESTAMP_SECOND,
        },
        .type               = VERSION_CONFIG_BUILD_INFO_TYPE,
        .optimization_level = VERSION_CONFIG_BUILD_INFO_OPTIMIZATION_LEVEL,
    },
    .git_info =
    {
        .short_sha  = VERSION_CONFIG_GIT_INFO_SHORT_SHA,
        .is_dirty   = VERSION_CONFIG_GIT_INFO_IS_DIRTY,
    },
};

// Local Functions -----------------------------------------------------------------------------------------------------
// Global Functions ----------------------------------------------------------------------------------------------------
