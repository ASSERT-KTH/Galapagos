btc_write32be(uint8_t *zp, uint32_t x) {
#ifdef BTC_BIGENDIAN
  memcpy(zp, &x, sizeof(x));
#else
  zp[0] = (uint8_t)(x >> 24);
  zp[1] = (uint8_t)((x & 0x00ff0000) >> 16);
  zp[2] = (uint8_t)((x & 0x0000ff00) >> 8);
  zp[3] = (uint8_t)(x & 0x000000ff);
#endif
}