btc_uint32_write(uint8_t *zp, uint32_t x) {
#ifdef BTC_BIGENDIAN
  *zp++ = (x & 0xFF);
  x >>= 8;
  *zp++ = (x & 0xFF);
  x >>= 8;
  *zp++ = (x & 0xFF);
  x >>= 8;
  *zp++ = (x & 0xFF);
  return zp;
#else
  uint8_t *xp = (uint8_t*)&x;
  *zp++ = *xp++;
  *zp++ = *xp++;
  *zp++ = *xp++;
  *zp++ = *xp;
  return zp;
#endif
}