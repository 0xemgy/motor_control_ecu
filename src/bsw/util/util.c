
#include "util.h"

void util_memcpy32(uint32_t *dst, const uint32_t *src, uint32_t len)
{
    for(uint32_t i = (uint32_t)0; i < len; i++)
    {
        dst[i] = src[i];
    }
}

void util_memset32(uint32_t *dst, uint32_t val, uint32_t len)
{
    for(uint32_t i = (uint32_t)0; i < len; i++)
    {
        dst[i] = val;
    }
}
