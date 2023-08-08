btc_write32be(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  uint8_t *p = (uint8_t *)&x; 
  zp[0] = p[3];
  zp[1] = p[2];
  zp[2] = p[1];
  zp[3] = p[0];
#else
  zp[0] = (uint8_t)(x >> 24 & 0xFF);
  zp[1] = (uint8_t)(x >> 16 & 0xFF);
  zp[2] = (uint8_t)(x >>  8 & 0xFF);
  zp[3] = (uint8_t)(x & 0xFF);
#endif
}