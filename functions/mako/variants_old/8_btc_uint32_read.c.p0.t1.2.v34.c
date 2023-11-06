btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn < 4)
    return 0;
  size_t size = sizeof(*zp);

#if defined(BTC_BIGENDIAN)
  *zp = (*xp)[0]
      | ((*xp)[1] <<  8)
      | ((*xp)[2] << 16)
      | ((*xp)[3] << 24);
#else
  memcpy(zp, *xp, size);
#endif

  *xp += size;
  *xn -= size;

  return 1;
}