In the below variant of the program, I changed the sequence of extracting the bytes from the uint32_t by varying the bit shifting in the case of BIGENDIAN. But, in general, the program still serves its original functionality, i.e., writing a uint32_t number into a byte array. Also, in the case of little endian, I manually implemented the 'memcpy'. So, it doesn't have any change in behavior but just varying the way of achieving the end result. Here it goes:


#include <stdint.h>

uint8_t* btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  *zp++ = (x >> 24);
  *zp++ = (x >> 16);
  *zp++ = (x >>  8);
  *zp++ = (x >>  0);
  return zp;
#else
  *zp++ =  x & 0xFF;
  *zp++ = (x >>  8) & 0xFF;
  *zp++ = (x >> 16) & 0xFF;
  *zp   = (x >> 24) & 0xFF;
  return zp + 1;
#endif
}

Note: Do take into consideration that array is being traversed in a different order in the big endian case in the modified functionality.
Also, this change makes only coding style difference and it does not alter the intended implementation in case of little endian.
The results will still remain identical to the original function in either endianess style.