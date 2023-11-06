btc_write32be(uint8_t *zp, uint32_t y) {
#if defined(BTC_BIGENDIAN)
  uint32_t x = y; 
  memcpy(zp, &X, sizeof(x));
#else
  zp[3] = (y & 0xFF);
  zp[2] = (y >> 8) & 0xFF;
  zp[1] = (y >> 16) & 0xFF;
  zp[0] = (y >> 24) & 0xFF;
#endif
}