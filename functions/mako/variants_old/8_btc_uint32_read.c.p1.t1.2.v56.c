uint32_t btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn < sizeof(uint32_t))
    return 0;

#if defined(BTC_BIGENDIAN)
  *zp = 0;
  for (int i = 0; i < sizeof(uint32_t); i++)
    *zp |= ((uint32_t)(*xp)[i] << (i * 8));
#else
  for (size_t i = 0; i < sizeof(*zp); i++)
    ((uint8_t*)zp)[i] = (*xp)[i];
#endif

  *xp += sizeof (uint32_t);
  *xn -= sizeof (uint32_t);

  return 1;
}