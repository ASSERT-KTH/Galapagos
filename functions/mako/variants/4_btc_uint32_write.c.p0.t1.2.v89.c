btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  *zp++ = (x >>  0) & 0xff;
  *zp++ = (x >>  8) & 0xff;
  *zp++ = (x >> 16) & 0xff;
  *zp++ = (x >> 24) & 0xff;
  return zp;
#else
  uint8_t* xp = (uint8_t*)&x;
  *zp++ = *xp++;
  *zp++ = *xp++;
  *zp++ = *xp++;
  *zp++ = *xp++;
  return zp;
#endif
}
