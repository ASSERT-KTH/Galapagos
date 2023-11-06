Variant 1:

btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn < 4)
    return 0;

#if defined(BTC_BIGENDIAN)
  for(int i = 0; i < 4; i++)
    *zp |= ((uint32_t)(*xp)[i] << i*8);  
#else
  for(int i = 0; i < sizeof(*zp); i++)
    (*zp)[i] = (*xp)[i];
#endif 

  *xp += 4;
  *xn -= 4;

  return 1;
}


Variant 2:

btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  
  if (*xn >= 4) {
    
    #if defined(BTC_BIGENDIAN)
      *zp = (*xp)[0] | (*xp)[1] << 8 | (*xp)[2] << 16 | (*xp)[3] << 24;
    #else
      int i;
      for (i = 0; i < sizeof(*zp); i++)
        ((uint8_t*)zp)[i] = (*xp)[i];
    #endif

    *xp += 4;
    *xn -= 4;
 
    return 1;
  }
  
  return 0;
}


Variant 3:

btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
    
  if (*xn < sizeof(*zp)) {
    return 0;
  }

#if defined(BTC_BIGENDIAN)
  *zp = 0;
  for (int i = 0; i < 4; i++)
    *zp |= ((*xp)[i] << (i * 8));
#else 
  *zp = *((uint32_t *)*xp);
#endif 

  *xp += sizeof(uint32_t);
  *xn -= sizeof(uint32_t);

  return 1;

}
