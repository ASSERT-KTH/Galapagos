void btc_write32be(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  *(uint32_t*)zp = x;
#else
  zp[0] = ((x & 0xff000000) >> 24);
  zp[1] = ((x & 0x00ff0000) >> 16);
  zp[2] = ((x & 0x0000ff00) >> 8);
  zp[3] = ((x & 0x000000ff));
#endif
}