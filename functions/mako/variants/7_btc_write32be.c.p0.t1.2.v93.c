btc_write32be(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  zp[3] = (x >> 24);
  zp[2] = (x >> 16);
  zp[1] = (x >>  8);
  zp[0] = (x >>  0);
#else
  uint8_t* xp = (uint8_t*) &x;
  zp[0] = xp[3];
  zp[1] = xp[2];
  zp[2] = xp[1];
  zp[3] = xp[0];
#endif
}