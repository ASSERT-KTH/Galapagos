The program variant could reverse the byte order for little-endian processors:


btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  *zp++ = (x >> 24);
  *zp++ = (x >> 16);
  *zp++ = (x >>  8);
  *zp++ = (x >>  0);
  return zp;
#else
  zp[0] = x >> 24;
  zp[1] = x >> 16;
  zp[2] = x >> 8;
  zp[3] = x;
  return zp + 4;
#endif
}


This program variant changes the byte ordering for both big-endian and little-endian machines but maintains its original functionality of writing 32-bit integer into memory. 

For the big-endian, the most significant byte (MSB) was originally placed at the lowest memory address, it is now placed at the highest address: reversing the byte order.

For the little-endian, The MSB which would have typically be placed at the highest address, is now placed at the lowest address with `memcpy` replaced by discrete operations, reversing the byte order to big-endian.