uint8_t* btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  zp[0] = (uint8_t)(x >>  0);
  zp[1] = (uint8_t)(x >>  8);
  zp[2] = (uint8_t)(x >> 16);
  zp[3] = (uint8_t)(x >> 24);
  return zp + 4;
#else
#if defined(__GNUC__)
  zp[0] = x & 0xFF;
  zp[1] = (x >>  8) & 0xFF;
  zp[2] = (x >> 16) & 0xFF;
  zp[3] = (x >> 24) & 0xFF;
#else
  memcpy(zp, &x, sizeof(uint32_t));
#endif
  return zp + sizeof(uint32_t);
#endif
}