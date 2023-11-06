Variant #1 - switch the endian condition 

btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn < 4)
    return 0;

#if defined(BTC_BIGENDIAN)
  memcpy(zp, *xp, sizeof(*zp));
#else
  *zp = ((uint32_t)(*xp)[0] <<  0)
      | ((uint32_t)(*xp)[1] <<  8)
      | ((uint32_t)(*xp)[2] << 16)
      | ((uint32_t)(*xp)[3] << 24);
#endif

  *xp += 4;
  *xn -= 4;

  return 1;
}


Variant #2 - Move increment/decrement operations inside the endian #if conditions, provide direct return

btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn < 4)
    return 0;

#if defined(BTC_BIGENDIAN)
  *zp = ((uint32_t)(*xp)[0] <<  0)
      | ((uint32_t)(*xp)[1] <<  8)
      | ((uint32_t)(*xp)[2] << 16)
      | ((uint32_t)(*xp)[3] << 24);
  *xp += 4;
  *xn -= 4;
#else
  memcpy(zp, *xp, sizeof(*zp));
  *xp += sizeof(*zp);
  *xn -= sizeof(*zp);
#endif

  return 1;
}


Variant #3 - Reorganize the code for easier reading, unroll '#if' conditionals 

btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn < 4) return 0;

#if defined(BTC_BIGENDIAN)
  *zp =  (*xp)[0] 
      | ((*xp)[1] <<  8)
      | ((*xp)[2] << 16)
      | ((*xp)[3] << 24);
#else
  memcpy(zp, *xp, sizeof(*zp));
#endif

  *xp += 4; *xn -= 4; return 1;
}


Variant #4 - Remove direct memory copying 

btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn < 4) return 0;

#if defined(BTC_BIGENDIAN)
  const uint32_t tmp = ((uint32_t)(*xp)[0] <<  0)
      | ((uint32_t)(*xp)[1] <<  8)
      | ((uint32_t)(*xp)[2] << 16)
      | ((uint32_t)(*xp)[3] << 24);
#else
  const uint32_t tmp = (*xp)[0] 
      | ((*xp)[1] <<  8)
      | ((*xp)[2] << 16)
      | ((*xp)[3] << 24);
#endif

  *zp = tmp; *xp += 4; *xn -= 4;

  return 1;
}
