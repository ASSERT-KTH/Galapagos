Your code should look like this:


void btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  zp[0] = (uint8_t)(x >> 0);
  zp[1] = (uint8_t)(x >> 8);
  zp[2] = (uint8_t)(x >> 16);
  zp[3] = (uint8_t)(x >> 24);
#else
  zp[0] = (uint8_t)x;
  zp[1] = (uint8_t)(x >> 8);
  zp[2] = (uint8_t)(x >> 16);
  zp[3] = (uint8_t)(x >> 24);
#endif
}

This variant changes the behavior because it doesn't increment the pointer, but as a replacement writes to different parts of the buffer given the index. The functionality does not change because the byte order of `uint32_t` `x` is correctly updated in the `uint8_t` buffer located at `zp`.