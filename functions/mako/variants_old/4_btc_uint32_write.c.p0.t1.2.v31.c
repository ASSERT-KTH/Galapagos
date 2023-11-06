btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  *zp++ = (uint8_t)(x >>  0);
  *zp++ = (uint8_t)(x >>  8);
  *zp++ = (uint8_t)(x >> 16);
  *zp++ = (uint8_t)(x >> 24);
#else
  uint8_t* xp = (uint8_t*)&x;
  *zp++ = *xp++;
  *zp++ = *xp++;
  *zp++ = *xp++;
  *zp++ = *xp++;
#endif
  return zp;
}