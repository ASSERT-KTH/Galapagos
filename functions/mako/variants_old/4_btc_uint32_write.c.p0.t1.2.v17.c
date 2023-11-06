btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  *zp++ = (x & 0xFF);
  x = x >> 8; 
  *zp++ = (x & 0xFF);
  x = x >> 8; 
  *zp++ = (x & 0xFF);
  x = x >> 8; 
  *zp++ = (x & 0xFF);
  return zp;
#else
  uint8_t* xp = (uint8_t*)&x;
  for (size_t i = 0; i < sizeof(x); ++i) {
    *zp++ = *xp++;
  }
  return zp;
#endif
}