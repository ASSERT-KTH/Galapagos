
#include <stdint.h>

uint8_t* btc_uint32_write(uint8_t *zp, uint32_t x) {
#ifdef BTC_BIGENDIAN
    uint8_t* temp = zp + 4;
    *zp++ = (x >> 24);
    *zp++ = (x >> 16) & 0xFF;
    *zp++ = (x >> 8) & 0xFF;
    *zp++ = x & 0xFF;
    return temp;
#else
    union endianChecker {
        uint32_t num;
        uint8_t byte[4];
    };

    union endianChecker var;
    var.num = x;

    *zp++ = var.byte[0];
    *zp++ = var.byte[1];
    *zp++ = var.byte[2];
    *zp++ = var.byte[3];

    return zp;
#endif
}

This variant differs from the reference implementation in the arrangement and bit shifting operations for the big-endian condition. It also replaces the `memcpy` operation in the else statement and directly saves the 4 bytes into the `zp` buffer using a union to determine the correct array of bytes for endian. The overall functionality stays the same while showcasing knowledge of bit manipulation and union usage in conforming to endian requirement.