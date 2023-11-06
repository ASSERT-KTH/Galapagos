btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if(*xn >= 4) {
#if defined ( BTC_BIGENDIAN )
    for (int i = 0; i < 4; ++i) {
      *zp |= ((uint32_t)(*xp)[i] << (i * 8));
    }
#else
    for (int i = 0; i < sizeof(*zp); ++i) {
      ((uint8_t*)zp)[i] = (*xp)[i];
    }
#endif
    *xp += 4;
    *xn -= 4;
    return 1;
  }
  return 0;
}