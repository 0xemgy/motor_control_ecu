#include <stdint.h>

#define UTIL_LEN(x) ((uint32_t)sizeof(x)/(uint32_t)sizeof(x[0]))

void util_memcpy32(uint32_t *dst, const uint32_t *src, uint32_t len);
void util_memset32(uint32_t *dst, uint32_t val, uint32_t len);
