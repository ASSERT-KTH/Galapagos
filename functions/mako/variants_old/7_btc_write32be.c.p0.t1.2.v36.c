btc_write32be(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  uint32_t y = x;
  memcpy(zp, &y, sizeof(y));
#else
  zp[3] = (x & 0x000000ff);
  x = x >> 8;
  zp[2] = (x & 0x000000ff);
  x = x >> 8;
  zp[1] = (x & 0x000000ff);
  x = x >> 8;
  zp[0] = (x & 0x000000ff);
#endif
}