btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  *zp++ = (x &   0xFF);
  *zp++ = (x >>  8) & 0xFF;
  *zp++ = (x >> 16) & 0xFF;
  *zp++ = (x >> 24) & 0xFF;
  return zp;
#else
  for(uint8_t i = 0; i < sizeof(x); i++) {
    *zp++ = *((uint8_t *)&x + i);
  }
  return zp;
#endif
}