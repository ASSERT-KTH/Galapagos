Sure, here is an alternate implementation of the same function that maintains the original function's functionality:


btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  zp[0] = (x >> 24) & 0xFF;
  zp[1] = (x >> 16) & 0xFF;
  zp[2] = (x >>  8) & 0xFF;
  zp[3] = (x >>  0) & 0xFF;
  return zp + 4;
#else
  zp[0] = x & 0xFF;
  zp[1] = (x >> 8) & 0xFF;
  zp[2] = (x >> 16) & 0xFF;
  zp[3] = (x >> 24) & 0xFF;
  return zp + 4;
#endif
}


This version uses array-style access to the byte pointer instead of incrementing it and uses bitwise AND to method to isolate the respective bytes. The write order/shift depends on the endianness. Finally, it moves data pointer forward and returns it. This function does identical action to the original but slightly different coding approach.