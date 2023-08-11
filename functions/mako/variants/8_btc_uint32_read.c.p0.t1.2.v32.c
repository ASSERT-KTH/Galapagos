btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (!zp || !xp || !*xp || !xn)
    return 0;

  if (*xn < sizeof(uint32_t))
    return 0;

#if defined(BTC_BIGENDIAN)
  *zp = ((*xp)[3] << 0)
      | ((*xp)[2] << 8)
      | ((*xp)[1] << 16)
      | ((*xp)[0] << 24);
#else
  *zp = **(uint32_t**)xp;
#endif

  *xp += sizeof(uint32_t);
  *xn -= sizeof(uint32_t);

  return 1;
}