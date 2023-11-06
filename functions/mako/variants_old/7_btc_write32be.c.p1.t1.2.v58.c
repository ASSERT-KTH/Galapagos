void btc_write32be(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  memcpy(zp, &x, sizeof(x));
#else
  for(int i = 0; i < sizeof(uint32_t); i++) {
    zp[i] = (x >> ((sizeof(uint32_t) - i - 1) * 8));
  }
#endif
}