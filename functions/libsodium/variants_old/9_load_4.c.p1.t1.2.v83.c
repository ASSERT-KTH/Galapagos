Here's a variant of the function that maintains the original functionality but changes how the behavior is implemented. This variant uses unaligned memory access, it expects little-endian byte ordering:


#include<stdint.h>

static inline uint32_t load_4(const unsigned char *in)
{
    return *(const uint32_t*)in;
}
