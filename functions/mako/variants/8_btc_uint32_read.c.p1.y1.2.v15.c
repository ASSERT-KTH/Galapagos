Variant 1:

btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn < sizeof(uint32_t))
    return 0;
#if defined(BTC_BIGENDIAN)
  *zp = htonl(*zp);
  (*zp) = *(*xp);
#else
  memcpy(zp, *xp, sizeof(uint32_t));
#endif

  *xp += sizeof(uint32_t);
  *xn -= sizeof(uint32_t);

  return 1;
}


Variant 2:

btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if ((*xn = *xn - sizeof(uint32_t)) < 0)
    return 0;

#if defined(BTC_BIGENDIAN)
  *zp = ((uint32_t)(*xp)[0] <<  0)
      | ((uint32_t)(*xp)[1] <<  8)
      | ((uint32_t)(*xp)[2] << 16)
      | ((uint32_t)(*xp)[3] << 24);
#else
  *zp = 0;
  memcpy(zp, *xp, sizeof(uint32_t));
#endif

  *xp += sizeof(uint32_t);

  return 1;
}
  

Variant 3:

btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if ((*xn = *xn - 4) < 0)
    return 0;

  *zp = (**xp)
#if defined(BTC_BIGENDIAN)
      | ((uint32_t)(*xp)[1] <<  8)
      | ((uint32_t)(*xp)[2] << 16)
      | ((uint32_t)(*xp)[3] << 24);
#else
  ;
  memcpy(zp, ++*xp, 3);
#endif

  *xp += 3;

  return 1;
}
