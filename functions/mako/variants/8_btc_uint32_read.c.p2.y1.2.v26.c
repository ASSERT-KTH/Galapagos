btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn < sizeof(*zp)) 
    return 0;

  uint32_t result = 0;

#if defined(BTC_BIGENDIAN)
  for (size_t i = 0; i < sizeof(*zp); ++i) {
    result |= ((uint32_t)(*xp)[i] << (i * 8));
  }
  *zp = result;
#else
  *zp = *((uint32_t*)*xp);
#endif

  *xp += sizeof(*zp);
  *xn -= sizeof(*zp);

  return 1;
}