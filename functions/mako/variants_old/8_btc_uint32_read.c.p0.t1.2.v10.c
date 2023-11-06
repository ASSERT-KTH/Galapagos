btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn < 4)
    return 0;

  uint32_t result = 0;

# if defined(BTC_BIGENDIAN)
  for(int i = 0; i < 4; i++) {
    result = result | (((uint32_t)(*xp)[i]) << (8 * i));
  }
  *zp = result;
#else
  memcpy(zp, *xp, sizeof(result));
#endif   
  *xp += 4;
  *xn -= 4;

  return 1;
}