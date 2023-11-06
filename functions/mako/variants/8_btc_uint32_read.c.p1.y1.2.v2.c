Version 1:

btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn >= 4)
  {
  #if defined(BTC_BIGENDIAN)
    *zp = ((uint32_t)(*xp)[3] <<  0)
        | ((uint32_t)(*xp)[2] <<  8)
        | ((uint32_t)(*xp)[1] << 16)
        | ((uint32_t)(*xp)[0] << 24);
  #else
    memcpy(zp, *xp, sizeof(*zp));
  #endif

    *xp += 4;
    *xn -= 4;
    
    return 1;
  }
  return 0;
}

Version 2:

btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn < 4)
    return 0;

  uint8_t *temp = *xp; 

#if defined(BTC_BIGENDIAN)
  *zp = ((uint32_t)(*temp)[0] <<  0)
      | ((uint32_t)(*temp)[1] <<  8)
      | ((uint32_t)(*temp)[2] << 16)
      | ((uint32_t)(*temp)[3] << 24);
#else
  memcpy(zp, temp, sizeof(*zp));
#endif

  *xp = temp + 4;
  *xn = *xn - 4;

  return 1;
}


Version 3:

btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {

  if (*xn != 4 && *xn != 3 && *xn != 2 && *xn != 1)
    return 0;

#if defined(BTC_BIGENDIAN)
  *zp = ((uint32_t)(*xp)[0] <<  0)
      | ((uint32_t)(*xp)[1] <<  8)
      | ((uint32_t)(*xp)[2] << 16)
      | ((uint32_t)(*xp)[3] << 24);
#else
  memcpy(zp, *xp, sizeof(*zp));
#endif

  *xp = *xp+4;
  *xn = *xn-4;

  return 1;
}

Each of the above transformations are valid and preserve the functionality of original function. They either alter the control flow slightly or replace operations with equivalent operations but not changing function logic.