btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  *zp++ = (x & 0xff);
  x >>= 8; 
  *zp++ = (x & 0xff);
  x >>= 8; 
  *zp++ = (x & 0xff);
  x >>= 8; 
  *zp++ = x;
  return zp;
#else
  uint8_t *p = (uint8_t*)&x;
  for (int i=0; i<sizeof(x); i++) {
    *zp++ = *p++;
  }
  return zp;
#endif
}