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

#define VERSION_PROJECT_NAME_MAX_LEN   ((uint32_t)32) /**< [byte] Project name maximum length */
#define VERSION_GIT_INFO_SHORT_SHA_LEN ((uint32_t)7)  /**< [byte] GIT SHA length */

// Global Data Types ---------------------------------------------------------------------------------------------------

/**
 * @brief Build type
 */
typedef enum version_build_type
{
    VERSION_BUILD_TYPE_RELEASE,
    VERSION_BUILD_TYPE_DEBUG,
    VERSION_BUILD_TYPE_MAX,
} version_build_type_t;

/**
 * @brief Build information
 */
typedef struct version_build_info
{
    util_timestamp_bcd_t         timestamp;          /**< Timestamp */
    version_build_type_t         type;               /**< Build type */
} version_build_info_t;

/**
 * @brief Git information
 */
typedef struct version_git_info
{
    char short_sha[VERSION_GIT_INFO_SHORT_SHA_LEN]; /**< SHA */
    bool is_dirty;                                  /**< Is dirty flag */
} version_git_info_t;

/**
 * @brief Version information
 */
typedef struct version_info
{
    uint32_t             magic_number;                               /**< Magic Number  */
    char                 project_name[VERSION_PROJECT_NAME_MAX_LEN]; /**< Project name */
    util_semver_bcd_t    sw_version;                                 /**< Software version */
    version_build_info_t build_info;                                 /**< Build information */
    version_git_info_t   git_info;                                   /**< Git information */
    uint32_t             code_size;                                  /**< [Byte] Code size */
} __attribute__((packed)) version_info_t ;

// Global Variables ----------------------------------------------------------------------------------------------------

extern const version_info_t version_info;      /**< Version */
extern const uint32_t       version_flash_crc; /**< CRC over whole data in flash  */

// Global Functions ----------------------------------------------------------------------------------------------------

#endif
