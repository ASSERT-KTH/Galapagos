btc_write32be(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  uint8_t b[4];
  b[0] = (x >> 24);
  b[1] = (x >> 16);
  b[2] = (x >>  8);
  b[3] = (x >>  0);
  memcpy(zp, &b, sizeof(b));
#else
  zp[0] = (x & 0x000000ff);
  zp[1] = (x & 0x0000ff00) >> 8;
  zp[2] = (x & 0x00ff0000) >> 16;
  zp[3] = (x & 0xff000000) >> 24;
#endif
}