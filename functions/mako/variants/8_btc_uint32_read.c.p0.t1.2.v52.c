btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  int offset = 4;

  if (*xn < offset)
    return 0;

#if defined(BTC_BIGENDIAN)
  for(int i = 0; i < offset; i++) {
    *zp += ((uint32_t)(*xp)[i] << (8*i));
  }
#else
  memcpy(zp, *xp, offset);
#endif
  
  *xp += offset;
  *xn -= offset;

  return 1;
}