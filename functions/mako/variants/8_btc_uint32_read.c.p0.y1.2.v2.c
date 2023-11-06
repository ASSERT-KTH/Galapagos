int btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn < sizeof(uint32_t))
    return 0;

#if defined(BTC_BIGENDIAN)
  *zp = (uint32_t)((*xp)[0]) 
      + ((uint32_t)((*xp)[1]) <<  8)
      + ((uint32_t)((*xp)[2]) << 16)
      + ((uint32_t)((*xp)[3]) << 24);
#else
  for(size_t i = 0; i < sizeof(*zp); ++i){
     ((uint8_t*)(zp))[i] = *((*xp) + i);
  }
#endif

  *xp += sizeof(uint32_t);
  *xn -= sizeof(uint32_t);

  return 1;
}