btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn < sizeof(*zp))
    return 0;

#if defined(BTC_BIGENDIAN)
  *zp = ((*xp)[0])
      | ((*xp)[1] <<  8)
      | ((*xp)[2] << 16)
      | ((*xp)[3] << 24);
#else
  memcpy(zp, *xp, sizeof(*zp));
#endif

  *xp += sizeof(*zp);
  *xn -= sizeof(*zp);

  return 1;
}