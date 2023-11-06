Here's the variant function. We maintain the function's signature and behavior on both big and little endian systems. I have just changed the reference wrapper and replace the actual calls with a direct byte shift method while keeping the logic the same.


void btc_uint32_write(uint8_t *zp, uint32_t x) {
#ifdef BTC_BIGENDIAN
  zp[0] = (uint8_t) ((x >>  0) & 0xff);
  zp[1] = (uint8_t) ((x >>  8) & 0xff);
  zp[2] = (uint8_t) ((x >> 16) & 0xff);
  zp[3] = (uint8_t) ((x >> 24) & 0xff);
    
#else
  zp[0] = (uint8_t) ((x >> 0 ) & 0xff);
  zp[1] = (uint8_t) ((x >> 8 ) & 0xff);
  zp[2] = (uint8_t) ((x >> 16) & 0xff);
  zp[3] = (uint8_t) ((x >> 24) & 0xff);
#endif
}

This version of the function first cast the pieced off byte of the 32-bit integer to an 8-bit unsigned integer before writing it to the memory.