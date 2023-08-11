Here is an alternative variant of the function that both reverses a source byte array into a destination byte array and returns a 32 bits integer while maintaining the behaviour of the original function.


#include <stdint.h>

uint32_t btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
    uint32_t z = 0;
    for (int i = 0; i < sizeof(z); i++)
        z = (z << 8) | xp[i];
#else
    uint32_t z;
    for(int i = sizeof(z); i > 0; i--)
        ((uint8_t*)&z)[i-1] = xp[sizeof(z)-i];
#endif
    return z;
}

This code works for both little-endian and big-endian systems. It uses a loop instead of hard coded values to ensure its application over a variety of data sizes. On a big-endian system, it manually shifts the 32-bit integer in the correct order. On a little-endian system, it reverses the inputs. The sizeof operator is macOS-agnostic, i.e, it automatically takes care of the differences between 32- and 64-bit systems' memory management.