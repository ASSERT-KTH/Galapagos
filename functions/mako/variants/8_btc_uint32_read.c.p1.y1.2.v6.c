Variation 1


btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn < sizeof(uint32_t))
    return 0;
    
#if defined(BTC_BIGENDIAN)
  *zp = ((uint32_t)(*xp)[0])
      | ((uint32_t)(*xp)[1] <<  8)
      | ((uint32_t)(*xp)[2] << 16)
      | ((uint32_t)(*xp)[3] << 24);
#else
  for(size_t i=0; i<sizeof(uint32_t); i++) 
    *zp |= *(*xp+i) << (i*8);
#endif

  *xp += sizeof(uint32_t);
  *xn -= sizeof(uint32_t);

  return 1;
}


Variation 2


btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn < sizeof(*zp))
  return 0;
  
#if defined(BTC_BIGENDIAN)
  *((uint8_t*)zp+0) = *(*xp+0);
  *((uint8_t*)zp+1) = *(*xp+1);
  *((uint8_t*)zp+2) = *(*xp+2);
  *((uint8_t*)zp+3) = *(*xp+3);
#else
  for(size_t i=0; i<sizeof(*zp); i++) 
    *((uint8_t*)zp+i) =  *(*xp+i);
#endif

  *xp += sizeof(*zp);
  *xn -= sizeof(*zp);

  return 1;
}


Variation 3


btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn < 4)
    return 0;
  
  uint32_t temp = 0;
#if defined(BTC_BIGENDIAN)
  temp = ((uint32_t)(*xp)[0])
         | ((uint32_t)(*xp)[1] <<  8)
         | ((uint32_t)(*xp)[2] << 16)
         | ((uint32_t)(*xp)[3] << 24);
#else
  memcpy(&temp, *xp, 4);
#endif
  *zp = temp;

  *xp += 4;
  *xn -= 4;

  return 1;
}

