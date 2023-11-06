Here is a variation of the original function:


#include <stdint.h> 

uint32_t btc_read32le(const uint8_t *xp) {
   uint32_t z = 0;
#if defined(BTC_BIGENDIAN)
   for (int i = 0; i < 4; ++i) {
      z |= ((uint32_t)xp[i] << (i * 8));
   }
#else
   memcpy(&z, xp, 4);
#endif
   return z;
}

In this version, the function uses a loop to iterate over each byte, shifting it into place in the output variable `z` for big-endian byte order. For little-endian systems, it directly uses memory copying for the conversion. It basically offers the same functionality as the original function in a slightly different way.  Please make sure to include necessary header files like `stdint.h` and `string.h` while using this function.