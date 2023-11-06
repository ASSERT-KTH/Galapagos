int btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn < sizeof(uint32_t))
    return 0;

#if defined(BTC_BIGENDIAN)
  *zp = ((uint32_t)(*xp)[3] <<  0)
      | ((uint32_t)(*xp)[2] <<  8)
      | ((uint32_t)(*xp)[1] << 16)
      | ((uint32_t)(*xp)[0] << 24);
#else
  *zp = *(*xp);
  *(*xp)++;
  *zp |= *(*xp) << 8;
  *(*xp)++;
  *zp |= *(*xp) << 16;
  *(*xp)++;
  *zp |= *(*xp) << 24;
  *(*xp)++;
#endif

  *xn -= sizeof(uint32_t);

  return 1;
}