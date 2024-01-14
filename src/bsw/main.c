
#include "util.h"
#include "util_mem.h"

#include <stdint.h>
#include <string.h>
#include "version.h"

void unused_test_func(void);

int main(void)
{
    uint32_t val = 5;

    if (val == 5 && version.sw_version.major == 0x10)
    {
        val = 4;
    }

    unused_test_func();

    while (1)
    {
        __asm__ volatile("nop");
    }

    return 0;
}


void unused_test_func(void)
{
    uint32_t src[5];
    uint32_t dst[5];

    src[0] = 0;
    // src[1] = 1;
    // src[2] = 2;
    // src[3] = 3;
    // src[4] = 4;

    util_mem_memcpy32(dst, src, UTIL_LEN(src));
    memcpy(dst, src, UTIL_LEN(src));

    return;
}
