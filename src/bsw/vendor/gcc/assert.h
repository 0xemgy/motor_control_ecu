/**
 * @file assert.h
 * @author 0xemgy (0xemgy@gmail.com)
 * @brief System header reduced to allowed types and defines
 *
 * @copyright Copyright (c) 2024 0xemgy
 */

#ifndef ASSERT_H
#define ASSERT_H

// Global Includes -----------------------------------------------------------------------------------------------------
// Global Defines ------------------------------------------------------------------------------------------------------

#ifdef NDEBUG /* required by ANSI standard */
#define assert(__e) ((void)0)
#else
// #define assert(__e) ((__e) ? (void)0 : assert_config_assert(__FILE__, __LINE__, __ASSERT_FUNC, #__e))
#define assert(__e) if(!(__e)){while(1) { __asm__ volatile ("nop"); } }
#endif

// Global Data Types ---------------------------------------------------------------------------------------------------
// Global Variables ----------------------------------------------------------------------------------------------------
// Global Functions ----------------------------------------------------------------------------------------------------

void assert_config_assert(const char *file, int32_t line, const char *function, const char *expression);

#endif
