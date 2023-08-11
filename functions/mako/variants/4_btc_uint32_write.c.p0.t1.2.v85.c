btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  *zp = (x >> 0); zp++;
  *zp = (x >> 8); zp++;
  *zp = (x >> 16); zp++;
  *zp = (x >> 24); 
  return zp + 1;
#else 
  uint8_t* xp = (uint8_t*)&x;
  for(int i = 0; i < 4; i++){
      *zp = *xp;
      zp++; xp++;
  }
  return zp;
#endif
}