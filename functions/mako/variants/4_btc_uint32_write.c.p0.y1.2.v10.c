The following code is a function in C which acts as a substitute for the provided btc_uint32_write function:


void btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  zp[0] = (x & 0xff);
  zp[1] = ((x >> 8) & 0xff);
  zp[2] = ((x >> 16) & 0xff);
  zp[3] = ((x >> 24) & 0xff);
#else
  uint8_t* xp = (uint8_t*)&x;
  zp[0] = xp[0];
  zp[1] = xp[1];
  zp[2] = xp[2];
  zp[3] = xp[3];
#endif
}

This function works the same as the original, writing the same values to the same locations in memory, but uses indexing instead of incrementing the pointer for the bitwise-shift side of the #if, and discretely copies each byte instead of using memcpy() for the other path. No helper or auxiliary functions are created.