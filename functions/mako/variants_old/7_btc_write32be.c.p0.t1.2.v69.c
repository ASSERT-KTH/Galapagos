btc_write32be(uint8_t *zp, uint32_t y) {
#if defined(BTC_BIGENDIAN)
  uint32_t x = y;
  memcpy(zp, &x, sizeof(x));
#else
  uint32_t x = y;
  zp[0] = (uint8_t) (x >> 24);
  zp[1] = (uint8_t) (x >> 16);
  zp[2] = (uint8_t) (x >> 8);
  zp[3] = (uint8_t) (x);
#endif
}