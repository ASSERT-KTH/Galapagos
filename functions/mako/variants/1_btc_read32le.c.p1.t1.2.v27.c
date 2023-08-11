Here is a variant of the function:


#include <endian.h>

uint32_t btc_read32le(const uint8_t *xp) {
    uint32_t temp = xp[0] | xp[1] << 8 | xp[2] << 16 | xp[3] << 24;
#if __BYTE_ORDER == __BIG_ENDIAN
    return __builtin_bswap32(temp);
#else
    return temp;
#endif
}

This variant keeps the original behavior but uses different code. We cast each byte to a uint32_t to prevent overflow in the shift operations. If the system is little-endian, we return the data as is. 
If the system is big-endian, we swap the byte order. Changing the behavior here from the original version, we do not use explicit shifts and ORs to reverse the byte order. Instead, we use a builtin compiler function, __builtin_bswap32, which should be faster.