
btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn < 4) 
    return 0;

#if defined(BTC_BIGENDIAN)
  uint32_t res = 0;
  for(int i = 0; i < 4; i++){
  	res = (res<<8) | (*xp)[i];
  }
  *zp = res;
#else
  *zp = *((uint32_t*)(*xp));
#endif

  *xp += 4;
  *xn -= 4;

  return 1;
}
