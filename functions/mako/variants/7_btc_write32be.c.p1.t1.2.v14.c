void btc_write32be(uint8_t *zp, uint32_t x) {
#ifndef BTC_BIGENDIAN
  x = ((x << 24) & 0xFF000000) |
      ((x << 8) & 0x00FF0000) |
      ((x >> 8) & 0x0000FF00) |
      ((x >> 24) & 0x000000FF);
#endif
  memcpy(zp, &x, sizeof(x));
}