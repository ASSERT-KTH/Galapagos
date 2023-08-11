btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn < sizeof(uint32_t))
    return 0;
  
#ifdef BTC_BIGENDIAN
  *zp = ((*xp)[0] | ((*xp)[1] << 8) | ((*xp)[2] << 16) | ((*xp)[3] << 24));
#else
  for(size_t i=0; i<sizeof(uint32_t); ++i){
    *((uint8_t*)zp +i) = *(*xp +i);
  }
#endif

  *xp += sizeof(uint32_t);
  *xn -= sizeof(uint32_t);

  return 1;
}