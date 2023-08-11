void btc_write32be(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  uint8_t *xp = (uint8_t *)&x;
  for (size_t i = 0; i < sizeof(x); ++i) {
    zp[i] = xp[i];
  }
#else
  for (size_t i = 0; i < sizeof(x); ++i) {
    zp[i] = (x >> (24 - 8 * i)) & 0xff;
  }
#endif
}