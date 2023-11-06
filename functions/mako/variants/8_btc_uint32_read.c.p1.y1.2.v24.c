Variant 1:


btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn < sizeof(*zp))
    return 0;

#if defined(BTC_BIGENDIAN)
  *zp = (uint32_t)(*xp)[0]
      | (((uint32_t)(*xp)[1]) << 8)
      | (((uint32_t)(*xp)[2]) << 16)
      | (((uint32_t)(*xp)[3]) << 24);
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

  *zp = 0;

#if defined(BTC_BIGENDIAN)
  for (int i = 0 ; i < 4; i++) {
      *zp |= (uint32_t)(*xp)[i] << (i * 8);
  }
#else
  memcpy(zp, *xp, 4);
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
  *zp = (*xp)[0] | ((*xp)[1] << 8) | ((*xp)[2] << 16)| ((*xp)[3] << 24);
#else
  memcpy(zp, *xp, sizeof(*zp));
#endif

  *xp = (*xp) + 4;
  *xn = (*xn) - 4;

  return 1;
}
