void btc_write32be(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  uint8_t *src = (uint8_t*)&x;
  zp[0] = src[0];
  zp[1] = src[1];
  zp[2] = src[2];
  zp[3] = src[3];
#else
  zp[0] = (uint8_t)(x / 16777216);         // equivalent to x >> 24
  zp[1] = (uint8_t)((x / 65536) % 256);    // equivalent to x >> 16
  zp[2] = (uint8_t)((x / 256) % 256);      // equivalent to x >> 8
  zp[3] = (uint8_t)(x % 256);              // equivalent to x >> 0
#endif
}