Variant 1 :


btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn < sizeof(uint32_t))
    return 0;

#if defined(BTC_BIGENDIAN)
  uint32_t temp = 0;
  for(int i = 0; i < 4; ++i) {
    temp |= (uint32_t)(*xp)[i] << (8 * i);
  }
  *zp = temp;
#else
  memcpy(zp, *xp, sizeof(*zp));
#endif

  *xp += sizeof(uint32_t);
  *xn -= sizeof(uint32_t);

  return 1;
}


Variant 2 :

 
btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn < sizeof(uint32_t))
    return 0;

#if defined(BTC_BIGENDIAN)
  const uint8_t *p = *xp;
  *zp  = *p++ << 24;
  *zp |= *p++ << 16;
  *zp |= *p++ << 8;
  *zp |= *p;
#else
  memcpy(zp, *xp, sizeof(*zp));
#endif

  *xp += sizeof(uint32_t);
  *xn -= sizeof(uint32_t);

  return 1;
}


Variant 3 :


btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn >= sizeof(uint32_t)) 
  { 
    #if defined(BTC_BIGENDIAN)
      *zp = ((uint32_t)(*xp)[0] <<  0)
        | ((uint32_t)(*xp)[1] <<  8)
        | ((uint32_t)(*xp)[2] << 16)
        | ((uint32_t)(*xp)[3] << 24);
    #else
      memcpy(zp, *xp, sizeof(*zp));
    #endif

    *xp += 4;
    *xn -= 4;

    return 1; 
  }
  return 0; 
}
