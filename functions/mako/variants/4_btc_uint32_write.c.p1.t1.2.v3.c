btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  *zp++ = x & 0xFF;
  *zp++ = (x >>  8) & 0xFF;
  *zp++ = (x >> 16) & 0xFF;
  *zp++ = (x >> 24) & 0xFF;
  return zp;
#else
  for(size_t i = 0; i < sizeof(x); i++, zp++) {
    *zp = ((x >> (i * 8)) & 0xFF);
  }
  
  return zp;
#endif
}