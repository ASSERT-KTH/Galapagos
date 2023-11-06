btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  zp[3] = (uint8_t)(x >>  24);
  zp[2] = (uint8_t)(x >>  16);
  zp[1] = (uint8_t)(x >>  8);
  zp[0] = (uint8_t)(x >>  0);
  return zp + 4;
#else
  for(int i = 0; i < sizeof(x); i++) {
    zp[i] = ((x >> (i*8)) & 0xff);
  }
  return zp + sizeof(x);
#endif
}