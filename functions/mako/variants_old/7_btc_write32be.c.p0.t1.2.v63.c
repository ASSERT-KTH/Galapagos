btc_write32be(uint8_t *zp, uint32_t y) {
#if defined(BTC_BIGENDIAN)
  uint32_t x = htonl(y);
  memcpy(zp, &x, sizeof(x));
#else
  zp[0] = (uint8_t)(y >> 24);
  zp[1] = (uint8_t)(y >> 16) & 0xff;
  zp[2] = (uint8_t)(y >>  8) & 0xff;
  zp[3] = (uint8_t)y & 0xff;
#endif
}