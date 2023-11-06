1. Using for-loop instead of memcpy:


btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn < 4)
     return 0;

  #if defined(BTC_BIGENDIAN)
  *zp = ((uint32_t)(*xp)[0] <<  0)
      | ((uint32_t)(*xp)[1] <<  8)
      | ((uint32_t)(*xp)[2] << 16)
      | ((uint32_t)(*xp)[3] << 24);
  #else
  for(int i=0; i<4; i++)
  {
    *((uint8_t*)zp+i)=(*xp)[i];
  }
  #endif 

  *xp += 4;
  *xn -= 4;
  return 1;
}


2. Using pointer arithmetic instead of array indexing:


btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn < 4)
    return 0;
 
  #if defined(BTC_BIGENDIAN)
  *zp = ((uint32_t)(**xp) <<  0)
      | ((uint32_t)(*(*xp+1)) <<  8)
      | ((uint32_t)(*(*xp+2)) << 16)
      | ((uint32_t)(*(*xp+3)) << 24);
  #else
  memcpy(zp, *xp, sizeof(*zp));
  #endif     

  *xp += 4;
  *xn -= 4;
  return 1;
}


3. Merging both of the above changes:


btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn < 4)
    return 0;

  #if defined(BTC_BIGENDIAN)
  *zp = ((uint32_t)(**xp) <<  0)
      | ((uint32_t)(*(*xp+1)) <<  8)
      | ((uint32_t)(*(*xp+2)) << 16)
      | ((uint32_t)(*(*xp+3)) << 24);
  #else
  for(int i=0; i<4; i++)
  {
    *((uint8_t*)zp+i)=*(*xp+i);
  }
  #endif

  *xp += 4;
  *xn -= 4;
  return 1;
}
