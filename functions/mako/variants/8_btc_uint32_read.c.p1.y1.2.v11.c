Variant 1:

btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn < sizeof(*zp))
    return 0;

#if defined(BTC_BIGENDIAN)
  *((uint8_t*)zp + 3) = (*xp)[0];
  *((uint8_t*)zp + 2) = (*xp)[1];
  *((uint8_t*)zp + 1) = (*xp)[2];
  *((uint8_t*)zp + 0) = (*xp)[3];
#else
  memcpy(zp, *xp, sizeof(*zp));
#endif

  *xp += sizeof(*zp);
  *xn -= sizeof(*zp);

  return 1;
}


Variant 2:

btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn < 4)
    return 0;

#if defined(BTC_BIGENDIAN)
  *zp = 0;
  int i;
  for(i = 0; i < 4; i++) {
    *zp |= ((uint32_t)(*xp)[i] << (8*(3-i)));
  }
#else
  memcpy(zp, *xp, sizeof(*zp));
#endif

  *xp += 4;
  *xn -= 4;

  return 1;
}


Variant 3:

btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn < 4) return 0;
#if defined(BTC_BIGENDIAN)
  for(int i = 0; i < 4; i++) {
    *zp <<= 8;
    *zp |= (*xp)[i];
  }
#else
  memcpy(zp, *xp, sizeof(*zp));
#endif
  *xp += 4;
  *xn -= 4;
  return 1;
}
