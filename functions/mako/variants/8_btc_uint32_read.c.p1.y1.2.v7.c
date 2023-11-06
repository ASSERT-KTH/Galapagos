Variant 1:

btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn < 4)
    return 0;

#if defined(BTC_BIGENDIAN)
  uint32_t b0 = *(*xp + 0) << 0;
  uint32_t b1 = *(*xp + 1) << 8;
  uint32_t b2 = *(*xp + 2) << 16;
  uint32_t b3 = *(*xp + 3) << 24;
  *zp = (b3 | b2 | b1 | b0);
#else
  *zp = *(const uint32_t *)(*xp);
#endif

  (*xp) += 4;
  (*xn) -= 4;

  return 1;
}

Variant 2:

btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn >= 4) {
#if defined(BTC_BIGENDIAN)
    const uint8_t* tv = *xp;
    *zp = (*tv << 0) | (*(tv+1) << 8) | (*(tv+2) << 16) | (*(tv+3) << 24);
#else
    *zp = *(const uint32_t *)(*xp);
#endif
    (*xp) += 4;
    (*xn) -= 4;
    return 1;
  }
  return 0;
}

Variant 3:

btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn < 4)
    return 0;

#if defined(BTC_BIGENDIAN)
  *zp = ((uint32_t)(*xp)[0])
      | ((uint32_t)(*xp)[1] <<  8)
      | ((uint32_t)(*xp)[2] << 16)
      | ((uint32_t)(*xp)[3] << 24);
#else
  *zp = **((uint32_t**)xp);
#endif

  *xp += sizeof(uint32_t);
  *xn -= sizeof(uint32_t);

  return 1;
}
