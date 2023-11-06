uint32_t btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn < sizeof(uint32_t))
    return 0;

#if defined(BTC_BIGENDIAN)
  uint8_t* data = (uint8_t*)zp;
  data[0] = (*xp)[0];
  data[1] = (*xp)[1];
  data[2] = (*xp)[2];
  data[3] = (*xp)[3];
#else
  for(size_t i = 0; i < sizeof(uint32_t); ++i) {
    ((uint8_t*)zp)[i] = (*xp)[i];
  }
#endif

  *xp += sizeof(uint32_t);
  *xn -= sizeof(uint32_t);

  return 1;
}