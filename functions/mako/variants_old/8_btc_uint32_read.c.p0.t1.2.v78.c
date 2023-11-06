
btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn < sizeof(*zp))
    return 0;

#if defined(BTC_BIGENDIAN)
  const uint8_t *ptr = *xp;
  *zp = (*ptr++ <<  0)
      | (*ptr++ <<  8)
      | (*ptr++ << 16)
      | (*ptr << 24);
#else
  memcpy(zp, *xp, sizeof(*zp));
#endif

  *xp += sizeof(*zp);
  *xn -= sizeof(*zp);

  return (*xn >= 0) ? 1 : 0;
}
