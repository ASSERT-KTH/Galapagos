btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  *zp++ = (x & 0xFF);
  *zp++ = (x >> 8) & 0xFF;
  *zp++ = (x >> 16) & 0xFF;
  *zp++ = (x >> 24) & 0xFF;
  return zp;
#else
  uint8_t* xp = (uint8_t*)&x;
  *zp++ = *xp++;
  *zp++ = *xp++;
  *zp++ = *xp++;
  *zp++ = *xp;
  return zp;
#endif
}