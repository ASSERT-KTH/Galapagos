Function Variant 1:

uint32_t btc_uint32_read_v1(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn < 4)
    return 0;

#if defined(BTC_BIGENDIAN)
  *zp = ((uint32_t)(*xp)[3] << 0) 
      | ((uint32_t)(*xp)[2] << 8)
      | ((uint32_t)(*xp)[1] << 16)  
      | ((uint32_t)(*xp)[0] << 24);
#else
  *zp = *((uint32_t*)(*xp));
#endif
  (*xp) += 4;
  (*xn) -= 4;

  return 1;
}

Function Variant 2:

uint32_t btc_uint32_read_v2(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn < 4)
    return 0;
      
#if defined(BTC_BIGENDIAN)
  (*zp) = (((*xp)[3]) | ((*xp)[2] << 8) | ((*xp)[1] << 16) | ((*xp)[0] << 24));
#else
  (*zp) = (*xp)[0] | ((*xp)[1] << 8) | ((*xp)[2] << 16) | ((*xp)[3] << 24);
#endif
  (*xp) += 4;
  (*xn) -= 4;

  return 1;
}

Function Variant 3:

uint32_t btc_uint32_read_v3(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn < sizeof(uint32_t))
    return 0;

#if defined(BTC_BIGENDIAN)
  *zp = (*xp)[0]
      | (*xp)[1] << 8
      | (*xp)[2] << 16
      | (*xp)[3] << 24;
#else
  *zp = (*(uint32_t*) *xp);
#endif

  *xp += sizeof(uint32_t);
  *xn -= sizeof(uint32_t);

  return 1;
}
