btc_write32be(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  uint8_t *xp = (uint8_t*)&x;
  for(int i=0;i<sizeof(x);++i)
    zp[i] = xp[i];
#else
  zp[0] = (uint8_t)(x >> 24) & 0xFF;
  zp[1] = (uint8_t)(x >> 16) & 0xFF;
  zp[2] = (uint8_t)(x >>  8) & 0xFF;
  zp[3] = (uint8_t)(x >>  0) & 0xFF;
#endif
}