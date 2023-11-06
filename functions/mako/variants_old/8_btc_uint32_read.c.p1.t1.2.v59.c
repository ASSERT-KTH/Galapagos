
btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn < sizeof(*zp))
    return 0;

#if defined(BTC_BIGENDIAN)
  ((uint8_t *)zp)[0] = (*xp)[0];
  ((uint8_t *)zp)[1] = (*xp)[1];
  ((uint8_t *)zp)[2] = (*xp)[2];
  ((uint8_t *)zp)[3] = (*xp)[3];
#else 
  *zp = *((uint32_t *)*xp);
#endif

  *xp += sizeof(*zp);
  *xn -= sizeof(*zp);

  return 1;
}
