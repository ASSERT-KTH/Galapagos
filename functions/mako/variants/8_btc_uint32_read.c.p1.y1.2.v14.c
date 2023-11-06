btc_uint32_read_v1(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn < sizeof(uint32_t))
    return 0;
  
#if defined(BTC_BIGENDIAN)
  *zp = ((uint32_t)(*xp)[3])
      | ((uint32_t)(*xp)[2] <<  8)
      | ((uint32_t)(*xp)[1] << 16)
      | ((uint32_t)(*xp)[0] << 24);
#else
  *zp = **(uint32_t**)xp;
#endif

  *xp += sizeof(uint32_t);
  *xn -= sizeof(uint32_t);

  return 1;
}


btc_uint32_read_v2(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  int i, result = 0;

  if (*xn < sizeof(uint32_t))
    return result;
  
#if defined(BTC_BIGENDIAN)
  for(i = 0; i < sizeof(uint32_t); i++){
    *zp |= ((uint32_t)(*xp)[i] <<(i*8) );
  } 
#else
  *zp = *((uint32_t*)*xp);
#endif
  *xp += sizeof(uint32_t);
  *xn -= sizeof(uint32_t);

  return !result;
}


btc_uint32_read_v3(uint32_t *zp, const uint8_t **xp, size_t *xn) {
   if (*xn < sizeof(*zp))
    return 0;

#if defined(BTC_BIGENDIAN)
  *zp = 0;
  *zp = (**xp<<24) | *zp; (*xp)++;
  *zp = (**xp<<16) | *zp; (*xp)++;
  *zp = (**xp<<8)  | *zp; (*xp)++;
  *zp = **xp       | *zp; (*xp)++;
#else
  *zp = *((uint32_t*)*xp);
#endif
  *xn -= sizeof(uint32_t);

  return 1;
}