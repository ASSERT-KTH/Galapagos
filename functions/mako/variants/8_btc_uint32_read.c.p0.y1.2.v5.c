int btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn < 4)
    return -1;

#if defined(BTC_BIGENDIAN)
  uint32_t u = 0;
  for (size_t i = 0; i < 4; ++i) {
    u |= (uint32_t)(*xp)[3 - i] << (i * 8);
  }
  
  *zp = u;
#else
  *zp = **xp | (*xp)[1] << 8 | (*xp)[2] << 16 | (*xp)[3] << 24;
#endif

  *xp += 4;
  *xn -= 4;

  return 0;
}