btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn < sizeof(uint32_t))
    return 0;

#if defined(BTC_BIGENDIAN)
  uint32_t temp = 0;
  for (uint8_t i = 0; i < 4; i++) {
    temp += ((uint32_t)(*xp)[i] <<  (i * 8));
  }
  *zp = temp;
#else
  memcpy(zp, *xp, sizeof(uint32_t));
#endif

  *xp += sizeof(uint32_t);
  *xn -= sizeof(uint32_t);

  return 1;
}