btc_write32be(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  uint8_t *p = (uint8_t *)&x;
  for (int i = 0; i < sizeof(x); ++i) {
    zp[i] = p[sizeof(x) - 1 - i];
  }
#else
  zp[0] = (x >> 24) & 0xFF;
  zp[1] = (x >> 16) & 0xFF;
  zp[2] = (x >>  8) & 0xFF;
  zp[3] = (x >>  0) & 0xFF;
#endif
}