btc_write32be(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  zp[0] = x >> 24;
  zp[1] = x >> 16;
  zp[2] = x >>  8;
  zp[3] = x;
#else
  zp[3] = (x & 0xff);
  zp[2] = (x >> 8)  & 0xff;
  zp[1] = (x >> 16) & 0xff;
  zp[0] = (x >> 24) & 0xff;
#endif
}