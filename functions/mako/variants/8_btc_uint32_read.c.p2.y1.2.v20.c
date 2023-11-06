btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn < sizeof(*zp))
    return 0;

#if defined(BTC_BIGENDIAN)
  const uint32_t shiftingHolder[] = { 0, 8, 16, 24 };
  uint32_t result = 0;
  for(int i = 0; i < sizeof(*zp); ++i) {
    result |= ((uint32_t)(*xp)[i] << shiftingHolder[i]);
  }
  *zp = result;
#else
  *zp = *((uint32_t *)(*xp));
#endif

  *xp += sizeof(*zp);
  *xn -= sizeof(*zp);

  return 1;
}