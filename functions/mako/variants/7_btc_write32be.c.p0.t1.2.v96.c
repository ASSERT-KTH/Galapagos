btc_write32be(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  *(uint32_t*)zp = x;
#else
  for(int i = 0; i < sizeof(x); i++) {
    zp[i] = x >> (24 - 8 * i);
  }
#endif
}