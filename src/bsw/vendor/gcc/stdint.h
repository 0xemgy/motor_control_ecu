/**
 * @file stdint.h
 * @author 0xemgy (0xemgy@gmail.com)
 * @brief System header stdint.h reduced to allowed types and defines
 *
 * @copyright Copyright (c) 2024 0xemgy
 */

#ifndef STDINT_H
#define STDINT_H

// Global Includes -----------------------------------------------------------------------------------------------------

typedef __INT8_TYPE__ int8_t;
typedef __INT16_TYPE__ int16_t;
typedef __INT32_TYPE__ int32_t;
typedef __INT64_TYPE__ int64_t;
typedef __UINT8_TYPE__ uint8_t;
typedef __UINT16_TYPE__ uint16_t;
typedef __UINT32_TYPE__ uint32_t;
typedef __UINT64_TYPE__ uint64_t;

#define INT8_MAX __INT8_MAX__
#define INT8_MIN (-INT8_MAX - 1)
#define UINT8_MAX __UINT8_MAX__
#define INT16_MAX __INT16_MAX__
#define INT16_MIN (-INT16_MAX - 1)
#define UINT16_MAX __UINT16_MAX__
#define INT32_MAX __INT32_MAX__
#define INT32_MIN (-INT32_MAX - 1)
#define UINT32_MAX __UINT32_MAX__
#define INT64_MAX __INT64_MAX__
#define INT64_MIN (-INT64_MAX - 1)
#define UINT64_MAX __UINT64_MAX__

// Global Defines ------------------------------------------------------------------------------------------------------
// Global Data Types ---------------------------------------------------------------------------------------------------
// Global Variables ----------------------------------------------------------------------------------------------------
// Global Functions ----------------------------------------------------------------------------------------------------

#endif
