/**
 * @file util_getter.h
 * @author 0xemgy (0xemgy@gmail.com)
 * @brief Different getter functions
 *
 * @copyright Copyright (c) 2024 0xemgy
 */

#ifndef UTIL_GETTER_H
#define UTIL_GETTER_H

// Global Includes -----------------------------------------------------------------------------------------------------

#include <stdbool.h>
#include <stdint.h>

// Global Defines ------------------------------------------------------------------------------------------------------
// Global Data Types ---------------------------------------------------------------------------------------------------

typedef enum util_getter_type
{
    UTIL_GETTER_TYPE_DIRECTLY,
    UTIL_GETTER_TYPE_BY_HANDLE,
    UTIL_GETTER_TYPE_MAX
} util_getter_type_t;

struct util_getter_bool_get_by_handle
{
    bool (*get)(uint32_t handle);
    uint32_t handle;
};

union util_getter_bool_functions
{
    bool (*get_directly)(void);
    struct util_getter_bool_get_by_handle get_by_handle;
};

typedef struct util_getter_bool
{
    util_getter_type_t               type;
    union util_getter_bool_functions functions;
} util_getter_bool_t;

struct util_getter_uint8_get_by_handle
{
    uint8_t (*get)(uint32_t handle);
    uint32_t handle;
};

union util_getter_uint8_functions
{
    uint8_t (*get_directly)(void);
    struct util_getter_uint8_get_by_handle get_by_handle;
};

typedef struct util_getter_uint8_t
{
    util_getter_type_t                type;
    union util_getter_uint8_functions functions;
} util_getter_uint8_t;

struct util_getter_int16_get_by_handle
{
    int16_t (*get)(uint32_t handle);
    uint32_t handle;
};

union util_getter_int16_functions
{
    int16_t (*get_directly)(void);
    struct util_getter_int16_get_by_handle get_by_handle;
};

typedef struct util_getter_int16_t
{
    util_getter_type_t                type;
    union util_getter_int16_functions functions;
} util_getter_int16_t;

struct util_getter_int32_get_by_handle
{
    int32_t (*get)(uint32_t handle);
    uint32_t handle;
};

union util_getter_int32_functions
{
    int32_t (*get_directly)(void);
    struct util_getter_int32_get_by_handle get_by_handle;
};

typedef struct util_getter_int32_t
{
    util_getter_type_t                type;
    union util_getter_int32_functions functions;
} util_getter_int32_t;
struct util_getter_int8_get_by_handle
{
    int8_t (*get)(uint32_t handle);
    uint32_t handle;
};

union util_getter_int8_functions
{
    int8_t (*get_directly)(void);
    struct util_getter_int8_get_by_handle get_by_handle;
};

typedef struct util_getter_int8_t
{
    util_getter_type_t               type;
    union util_getter_int8_functions functions;
} util_getter_int8_t;

struct util_getter_uint16_get_by_handle
{
    uint16_t (*get)(uint32_t handle);
    uint32_t handle;
};

union util_getter_uint16_functions
{
    uint16_t (*get_directly)(void);
    struct util_getter_uint16_get_by_handle get_by_handle;
};

typedef struct util_getter_uint16_t
{
    util_getter_type_t                 type;
    union util_getter_uint16_functions functions;
} util_getter_uint16_t;

struct util_getter_uint32_get_by_handle
{
    uint32_t (*get)(uint32_t handle);
    uint32_t handle;
};

union util_getter_uint32_functions
{
    uint32_t (*get_directly)(void);
    struct util_getter_uint32_get_by_handle get_by_handle;
};

typedef struct util_getter_uint32_t
{
    util_getter_type_t                 type;
    union util_getter_uint32_functions functions;
} util_getter_uint32_t;

// Global Variables ----------------------------------------------------------------------------------------------------
// Global Functions ----------------------------------------------------------------------------------------------------

#endif
