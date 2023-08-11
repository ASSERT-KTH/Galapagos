btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {

  if (*xn < sizeof(*zp))
    return 0;

#if defined(BTC_BIGENDIAN)
  uint32_t temp = ((*xp)[0] | (*xp)[1] << 8 | (*xp)[2] << 16 | (*xp)[3] << 24); 
  *zp = temp;
#else
  for (size_t i = 0; i < sizeof(*zp); i++) {
    ((uint8_t*)zp)[i] = (*xp)[i];
  }
#endif

  *xp += sizeof(*zp);
  *xn -= sizeof(*zp);

  return 1;
}