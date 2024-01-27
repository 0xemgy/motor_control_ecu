
#include "util.h"
#include "util_mem.h"

#include <stdint.h>
#include <string.h>
#include "version.h"

static void unused_test_func(void);

int main(void)
{
    volatile uint8_t val = (uint8_t)255;

    if ((val == (uint8_t)255) && (version.sw_version.major == (uint8_t)0x10))
    {
        val = 4;
    }

    unused_test_func(); // 3.2 non-compliant comment ends with backslash

    while (1)
    {
        __asm__ volatile("nop");
    }

    return 0;
}

// void misra_2_7_unused_param (int *param1, int unused_param)
// {
//     *param1 = 42U;
// }

static void unused_test_func(void)
{
    uint32_t src[5];
    uint32_t dst[5];

    src[0] = 0;
    // src[1] = 1;
    // src[2] = 2;
    // src[3] = 3;
    // src[4] = 4;

    util_mem_memcpy32(dst, src, UTIL_LEN(src));
    (void)memcpy(dst, src, UTIL_LEN(src));

    return;
}
