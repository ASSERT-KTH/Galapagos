btc_write32be(unsigned char *zp, uint32_t x) {

#if defined(BTC_BIGENDIAN)
  uint8_t *p = (uint8_t*)&x;
  for (size_t i = 0; i < sizeof(x); ++i) {
    zp[i] = p[i];
  }
#else
  for (size_t i = 0; i < sizeof(x); ++i) {
    zp[i] = (x >> (8 * (3 - i)));
  }
#endif
}