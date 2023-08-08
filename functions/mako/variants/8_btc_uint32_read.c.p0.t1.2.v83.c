btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  size_t size_needed = sizeof(*zp);
  if (*xn < size_needed)
    return 0;

#if defined(BTC_BIGENDIAN)
  *zp = ((*xp)[0] <<  0)
      | ((*xp)[1] <<  8)
      | ((*xp)[2] << 16)
      | ((*xp)[3] << 24);
#else
  memmove(zp, *xp, sizeof(*zp));
#endif

  *xp += size_needed;
  *xn -= size_needed;

  return 1;
}