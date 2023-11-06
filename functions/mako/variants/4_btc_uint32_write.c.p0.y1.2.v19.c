void btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  zp[0] = (uint8_t)(x >>  0);
  zp[1] = (uint8_t)(x >>  8);
  zp[2] = (uint8_t)(x >> 16);
  zp[3] = (uint8_t)(x >> 24);
  return zp + sizeof(uint32_t);
#else
  for (size_t i = 0; i < sizeof(x); ++i) {
    zp[i] = ((uint8_t*)&x)[i];
  }
  return zp + sizeof(uint32_t);
#endif
}