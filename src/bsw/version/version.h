/**
 * @file version.h
 * @author 0xemgy (0xemgy@gmail.com)
 * @brief Version information
 *
 * @copyright Copyright (c) 2024 0xemgy
 */

#ifndef VERSION_H
#define VERSION_H

// Global Includes -----------------------------------------------------------------------------------------------------

#include "util_semver.h"
#include "util_timestamp.h"

#include <stdbool.h>
#include <stdint.h>

// Global Defines ------------------------------------------------------------------------------------------------------

// Global Data Types ---------------------------------------------------------------------------------------------------

typedef enum version_build_type
{
    VERSION_BUILD_TYPE_RELEASE,
    VERSION_BUILD_TYPE_DEBUG,
    VERSION_BUILD_TYPE_MAX
} version_build_type_t;

typedef enum version_optimization_level
{
    VERSION_OPTIMIZATION_LEVEL_O0,
    VERSION_OPTIMIZATION_LEVEL_O1,
    VERSION_OPTIMIZATION_LEVEL_O2,
    VERSION_OPTIMIZATION_LEVEL_O3,
    VERSION_OPTIMIZATION_LEVEL_OFAST,
    VERSION_OPTIMIZATION_LEVEL_OS,
    VERSION_OPTIMIZATION_LEVEL_OZ,
    VERSION_OPTIMIZATION_LEVEL_MAX
} version_optimization_level_t;

typedef struct version_git_info
{
    uint32_t short_sha_bcd;
    bool    is_dirty;
} version_git_info_t;

struct VersionInfo
{
    char                 project_name[16];
    util_semver_bcd_t    sw_version;
    util_timestamp_bcd_t build_timestamp;
    version_git_info_t   git_info;
};

// Global Variables ----------------------------------------------------------------------------------------------------
// Global Functions ----------------------------------------------------------------------------------------------------

#endif
