void btc_write32be(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  // If the system is Big Endian, no conversion is necessary. Just copy the value.
  ((uint32_t*)zp)[0] = x;
#else
  // Little Endian conversion, each byte sequence reversed
  zp[0] = x & 0xff;
  zp[1] = (x >> 8) & 0xff;
  zp[2] = (x >> 16) & 0xff;
  zp[3] = (x >> 24) & 0xff;
#endif
}