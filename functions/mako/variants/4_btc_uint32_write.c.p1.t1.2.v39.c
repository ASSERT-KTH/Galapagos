
void btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  zp[0] = (x >>  0) & 0xFF;
  zp[1] = (x >>  8) & 0xFF;
  zp[2] = (x >> 16) & 0xFF;
  zp[3] = (x >> 24) & 0xFF;
#else
  zp[0] = (x >>  0) & 0xFF;
  zp[1] = (x >>  8) & 0xFF;
  zp[2] = (x >> 16) & 0xFF;
  zp[3] = (x >> 24) & 0xFF;
#endif
}


In the code above, for big-endian machines, instead of directly assigning the portions of x to be pointed to by zp++, and incrementing the pointer each time, the result of the shift operation and '&' binary operation is indexed on zp directly. Same operation is similarly performed for little-endian systems in divergence from using memcpy(). The shell operator was replaced with bitwise AND operation with 0xFF hex to make sure it's always just one byte that is kept from `uint32`. All changes still maintain the functions' original functionality of storing a `uint32` in the byte array for both big-endian and little-endian systems since it still breaks the `uint32` into bytes and ensures correct endianness.