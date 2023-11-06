btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn < sizeof(uint32_t)) 
    return 0;

#if defined(BTC_BIGENDIAN)
  *zp = 0;
  for (int i = 0; i < sizeof(uint32_t); i++) 
    *zp |= (uint32_t)(*xp)[i] << (i * 8);
#else
  // process one byte at a time instead of all 4 at once
  for (size_t i = 0; i < sizeof(uint32_t); i++, (*xp)++, (*xn)--)
    ((uint8_t*)zp)[i] = **xp;
#endif

  return 1;
}