btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn < sizeof(uint32_t))
    return 0;

#if defined(BTC_BIGENDIAN)
  const uint8_t *tmp = *xp;
  *zp = (*tmp++ <<  0)
      | (*tmp++ <<  8)
      | (*tmp++ << 16)
      | (*tmp   << 24);
#else
  *zp = (**xp)
      | ((uint32_t)(*xp)[1] << 8)
      | ((uint32_t)(*xp)[2] << 16)
      | ((uint32_t)(*xp)[3] << 24);
#endif

  *xp += sizeof(*zp);
  *xn -= sizeof(*zp);

  return 1;
}