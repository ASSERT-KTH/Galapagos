
btc_write32be(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  zp[0] = (uint8_t)(x >> 24);
  zp[1] = (uint8_t)(x >> 16);
  zp[2] = (uint8_t)(x >>  8);
  zp[3] = (uint8_t)(x >>  0);
#else
  uint32_t y = htonl(x);
  memcpy(zp, &y, sizeof(x));
#endif
}
