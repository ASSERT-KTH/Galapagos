void btc_write32be(uint8_t *zp, uint32_t x) {
#ifndef BTC_BIGENDIAN
  x = ((x & 0xff000000) >> 24) |
      ((x & 0x00ff0000) >> 8) |
      ((x & 0x0000ff00) << 8) |
      ((x & 0x000000ff) << 24);
#endif
  memcpy(zp, &x, sizeof(x));
}