uint32_t btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn < sizeof(uint32_t))
    return 0;
    
#if defined(BTC_BIGENDIAN)
  uint32_t val = 0;
  for(int i = 0; i < sizeof(uint32_t); i++) {
      val |= (*xp)[i] << (i * 8);
  }
  *zp = val;
#else
  memcpy(zp, *xp, sizeof(*zp));
#endif

  *xp += sizeof(uint32_t);
  *xn -= sizeof(uint32_t);

  return 1;
}