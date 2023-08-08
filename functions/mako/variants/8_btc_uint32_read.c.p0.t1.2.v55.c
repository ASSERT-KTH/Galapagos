btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {

  if (*xn >= 4) {
#if defined(BTC_BIGENDIAN)
    *zp = (*xp)[0] | ((*xp)[1] << 8) | ((*xp)[2] << 16) | ((*xp)[3] << 24);
#else 
    for (size_t i = 0; i < sizeof(*zp); ++i) {
      ((uint8_t*)zp)[i] = (*xp)[i];
    }
#endif
    *xp += sizeof(*zp);
    *xn -= sizeof(*zp);
    return 1;
  }
  return 0;
}