btc_write32be(uint8_t *zp, uint32_t x) {
#ifdef BTC_BIGENDIAN
  uint8_t *p = (uint8_t*)&x;
  for(int i = 0; i < sizeof(x); i++) {
    zp[i] = p[i];
  }
#else
  for(int i = 0; i < 4; i++) {
    zp[3-i] = (x >> (8 * i));
  }
#endif
}