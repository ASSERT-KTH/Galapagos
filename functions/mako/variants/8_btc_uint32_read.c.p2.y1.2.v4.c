btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn < 4)
    return 0;

#if defined(BTC_BIGENDIAN)
  for(int i=0; i<4; i++) {
      *zp = ((*zp)<<8) | ((uint32_t)(*xp)[i]); 
  }
  *zp = ((*zp)>>8);
#else
  *zp = *(uint32_t*)(*xp);
#endif

  *xp += 4;
  *xn -= 4;

  return 1;
}