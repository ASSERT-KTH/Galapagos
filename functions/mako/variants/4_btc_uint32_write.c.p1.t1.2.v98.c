Here's a variant of the function that maintains the original functionality but changes the condition for writing the value in big endian order. Rather than relying on preset definitions, it determines endianness at runtime.

The function:

#include <stdbool.h>
   
uint8_t* btc_uint32_write(uint8_t *zp, uint32_t x) {
    union {
        uint32_t i;
        char c[4];
    } endTest = {0x12345678};

    bool is_bigendian = endTest.c[0] == 0x12 ? true : false;
    
    if(is_bigendian) {
        *zp++ = (x >>  0);
        *zp++ = (x >>  8);
        *zp++ = (x >> 16);
        *zp++ = (x >> 24);
        return zp;
    } else {
        memcpy(zp, &x, sizeof(x));
        return zp + 4;
    }
}


The purpose of this `union` is to test the current machine’s endianess. The `uint32_t` 0x12345678 in hexadecimal matches to 3214213578 in decimal. When measuring in bytes, if the machine evaluates to it as the 1st byte being the smallest entity (small endian), it should be equal to 120(0x78). If the machine evaluates to it as the 1st byte being the most significant(big endian), it should be equal to 18(0x12).

We are checking the first char, and based on what we have defined, we are expecting 0x78 for little-endians (Because they store/arrange lower-order first) and 0x12 for big-endians.