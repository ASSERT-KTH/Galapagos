btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn < sizeof(*zp))
    return 0;

#if defined(BTC_BIGENDIAN)
  uint32_t t = 0;
  for (int i = 0; i < sizeof(*zp); i++) {
    t |= ((uint32_t)(*xp)[i] << (i * 8));
  }
  *zp = t;
#else
  *zp = *((uint32_t*)(*xp));
#endif

  *xp += sizeof(*zp);
  *xn -= sizeof(*zp);

  return 1;
}