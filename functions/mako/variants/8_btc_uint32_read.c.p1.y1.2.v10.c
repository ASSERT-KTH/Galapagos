Variant 1:

btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (!xp || !zp || !xn || *xn < 4) 
    return 0;

#if defined(BTC_BIGENDIAN)
  uint8_t *z = (uint8_t*) zp;
  *z = (*xp)[3]; z++;
  *z = (*xp)[2]; z++;
  *z = (*xp)[1]; z++;
  *z = (*xp)[0];
#else
  memcpy(zp, *xp, sizeof(*zp));
#endif

  *xp += 4;
  *xn -= 4;

  return 1;
}


Variant 2:

btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn < sizeof(uint32_t))
    return 0;

#if defined(BTC_BIGENDIAN)
  *zp = ((*xp)[3] | (*xp)[2] << 8 | (*xp)[1] << 16 | (*xp)[0] << 24);
#else
  memcpy(zp, *xp, sizeof(uint32_t));
#endif

  *xp += sizeof(uint32_t);
  *xn -= sizeof(uint32_t);

  return 1;
}


Variant 3:

btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn < 4) 
    return 0;

#if defined(BTC_BIGENDIAN)
  *zp = *(((uint32_t*) *xp)) & 0x000000FF
      | ((*(((uint32_t*) *xp)) & 0x0000FF00) >> 8)
      | ((*(((uint32_t*) *xp)) & 0x00FF0000) >> 16)
      | ((*(((uint32_t*) *xp)) & 0xFF000000) >> 24);
#else
  memcpy(zp, *xp, 4);
#endif

  *xp += 4;
  *xn -= 4;

  return 1;
}
