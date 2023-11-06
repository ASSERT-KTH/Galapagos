btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn < sizeof(*zp))
    return -1;

#if defined(BTC_BIGENDIAN)
  for (int i = 0; i < sizeof(*zp); i++)
    *zp |= ((uint32_t)(*xp)[i] << (8 * i));
#else
  for (int i = 0; i < sizeof(*zp); i++)
    ((uint8_t*)zp)[i] = (*xp)[i];
#endif

  *xp += sizeof(*zp);
  *xn -= sizeof(*zp);

  return 0;
}