btc_write32be(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  memcpy(zp, &x, sizeof(x));
#else
  zp[0] = (x >> 24);
  zp[1] = (x >> 16);
  zp[2] = (x >>  8);
  zp[3] = (x >>  0);
#endif
}