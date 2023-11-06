Variant 1:

btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn < 4)
    return 0;

  uint8_t *src = (uint8_t *)*xp;
  
#if defined(BTC_BIGENDIAN)
  *zp = ((uint32_t)src[0] <<  0)
      | ((uint32_t)src[1] <<  8)
      | ((uint32_t)src[2] << 16)
      | ((uint32_t)src[3] << 24);
#else
  *zp = 0;
  for(size_t i = 0; i < sizeof(*zp); ++i)
    *zp = (*zp << 8) + src[i];
#endif

  *xp += 4;
  *xn -= 4;

  return 1;
}


Variant 2:

btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn < 4)
    return 0;
  
#if defined(BTC_BIGENDIAN)
  *zp = (*xp)[0]
      | ((*xp)[1] <<  8)
      | ((*xp)[2] << 16)
      | ((*xp)[3] << 24);
#else
  int8_t *end = (int8_t *)(*xp + sizeof(*zp) - 1);
  while (end >= (int8_t*)*xp)
      *zp = (*zp << 8) + *end--;
#endif

  *xp += 4;
  *xn -= 4;

  return 1;
}


Variant 3:

btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn < 4)
    return 0;

#if defined(BTC_BIGENDIAN)
  
  *zp = ((uint32_t)(*xp)[3] <<  24)
      | ((uint32_t)(*xp)[2] <<  16)
      | ((uint32_t)(*xp)[1] << 8)
      | ((uint32_t)(*xp)[0] <<  0);
#else
  char *temp = (char *)zp;
  temp[0] = (*xp)[3];
  temp[1] = (*xp)[2];
  temp[2] = (*xp)[1];
  temp[3] = (*xp)[0];
#endif

  *xp += 4;
  *xn -= 4;

  return 1;
}

