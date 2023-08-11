Here's the improved version of your given C function with maintaining the signature. It alters original conditionally compiled blocks to follow Little-Endian and Big-Endian systems, but retains its functionality:


#include <stdint.h>

uint8_t* btc_uint32_write(uint8_t *zp, uint32_t x) {
#if !defined(BTC_BIGENDIAN)
    *zp++ = (uint8_t)(x >> 0);
    *zp++ = (uint8_t)(x >> 8);
    *zp++ = (uint8_t)(x >> 16);
    *zp++ = (uint8_t)(x >> 24);
#else
    *zp++ = (uint8_t)(x >> 24);
    *zp++ = (uint8_t)(x >> 16);
    *zp++ = (uint8_t)(x >> 8);
    *zp++ = (uint8_t)(x >> 0);
#endif
    return zp;
}


Updated code differs from the previous version as follows:
1. In the updated function, for little endian systems it ensures that the least significant byte of number is written first and for big endian systems, it ensures that most significant bytes are written first irrespective of being in memory. 
   
2. By using unsigned integer as byte array and array of integer bytes it obeys how the endian of a system stores integer. It fixes endianness on every platform following its simple assignments than using memcpy function.

3. Added cast to `uint8_t` to each pointer operation which prevents a possible warning about the automatic conversion from `uint32_t` to `uint8_t`.