/**
 * @file partition_info.h
 * @author 0xemgy (0xemgy@gmail.com)
 * @brief Partition_info information
 *
 * @copyright Copyright (c) 2024 0xemgy
 */

#ifndef PARTITION_INFO_H
#define PARTITION_INFO_H

// Global Includes -----------------------------------------------------------------------------------------------------

#include "util_semver.h"
#include "util_timestamp.h"

#include <stdbool.h>
#include <stdint.h>

// Global Defines ------------------------------------------------------------------------------------------------------

#define PARTITION_INFO_PROJECT_NAME_MAX_LEN   ((uint32_t)32) /**< [byte] Project name maximum length */
#define PARTITION_INFO_GIT_INFO_SHORT_SHA_LEN ((uint32_t)7)  /**< [byte] GIT SHA length */

// Global Data Types ---------------------------------------------------------------------------------------------------

/**
 * @brief Partition info header info bits
 */
typedef struct partition_info_header_info_bits
{
    uint8_t is_release_build : 1;  /**< Is release build */
    uint8_t is_git_repo_dirty : 1; /**< Is git repo dirty */
    uint8_t reserved : 6;          /**< Reserved */
} partition_info_header_info_bits_t;

/**
 * @brief Partition info header
 */
typedef struct partition_info_header
{
    char                              project_name[PARTITION_INFO_PROJECT_NAME_MAX_LEN]; /**< Project name */
    util_semver_t                     sw_version;                                        /**< Software version */
    char                              short_sha[PARTITION_INFO_GIT_INFO_SHORT_SHA_LEN];  /**< Git short SHA */
    partition_info_header_info_bits_t info_bits;                                         /**< Info bits */
    uint32_t                          start_address; /**< [Byte] Code start address */
    uint32_t                          code_size;     /**< [Byte] Code size (without trailer) */
    uint32_t                          header_crc;    /**< CRC over header */
} __attribute__((packed)) partition_info_header_t;

/**
 * @brief Partition info trailer
 */
typedef struct partition_info_trailer
{
    uint32_t         code_crc;    /**< CRC over whole code */
    util_timestamp_t timestamp;   /**< Build timestamp */
    uint32_t         trailer_crc; /**< CRC over trailer */
} __attribute__((packed)) partition_info_trailer_t;

// Global Variables ----------------------------------------------------------------------------------------------------

/**
 * @brief Partition info header
 */
extern const partition_info_header_t partition_info_header;

/**
 * @brief Partition info trailer
 */
extern const partition_info_trailer_t partition_info_trailer;

// Global Functions ----------------------------------------------------------------------------------------------------

#endif
