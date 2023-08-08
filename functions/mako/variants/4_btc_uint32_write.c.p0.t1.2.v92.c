btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  *zp = (x >>  0);
  zp++;
  *zp = (x >>  8);
  zp++;
  *zp = (x >> 16);
  zp++;
  *zp = (x >> 24);
  zp++;
  return zp;
#else
  for(int i = 0; i < sizeof(x); i++) {
    *zp = ((uint8_t*)&x)[i]; 
    zp++;
  }
  return zp;
#endif
}