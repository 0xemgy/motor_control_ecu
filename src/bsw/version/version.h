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

#define VERSION_PROJECT_NAME_MAX_LEN ((uint32_t)32)
#define VERSION_GIT_INFO_SHORT_SHA_LEN ((uint32_t)7)

// Global Data Types ---------------------------------------------------------------------------------------------------

typedef enum version_build_type
{
    VERSION_BUILD_TYPE_RELEASE,
    VERSION_BUILD_TYPE_DEBUG,
    VERSION_BUILD_TYPE_MAX,
    VERSION_BUILD_TYPE_UNKNOWN
} version_build_type_t;

typedef enum version_optimization_level
{
    VERSION_OPTIMIZATION_LEVEL_O0,
    VERSION_OPTIMIZATION_LEVEL_O1,
    VERSION_OPTIMIZATION_LEVEL_O2,
    VERSION_OPTIMIZATION_LEVEL_O3,
    VERSION_OPTIMIZATION_LEVEL_OFAST,
    VERSION_OPTIMIZATION_LEVEL_OG,
    VERSION_OPTIMIZATION_LEVEL_OS,
    VERSION_OPTIMIZATION_LEVEL_OZ,
    VERSION_OPTIMIZATION_LEVEL_MAX
} version_optimization_level_t;

typedef struct version_build_info
{
    util_timestamp_bcd_t timestamp;
    version_build_type_t type;
    version_optimization_level_t optimization_level;
} version_build_info_t;

typedef struct version_git_info
{
    char short_sha[VERSION_GIT_INFO_SHORT_SHA_LEN];
    bool is_dirty;
} version_git_info_t;

typedef struct version
{
    char                 project_name[VERSION_PROJECT_NAME_MAX_LEN];
    util_semver_bcd_t    sw_version;
    version_build_info_t build_info;
    version_git_info_t   git_info;
} version_t;

// Global Variables ----------------------------------------------------------------------------------------------------
// Global Functions ----------------------------------------------------------------------------------------------------

#endif
