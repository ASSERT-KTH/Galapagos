btc_write32be(uint8_t *zp, uint32_t y) {
#if defined(BTC_BIGENDIAN)
  memcpy(zp, &y, sizeof(y));
#else
  zp[3] = y & 0xFF;
  zp[2] = (y >> 8) & 0xFF;
  zp[1] = (y >> 16) & 0xFF;
  zp[0] = (y >> 24) & 0xFF;
#endif
}