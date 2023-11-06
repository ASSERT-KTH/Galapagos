btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  for (uint8_t bit = 0; bit <= 24; bit += 8) {
    *zp++ = (x >> bit);
  }
  return zp;
#else
  uint8_t *xp = (uint8_t *)&x;
  for (uint8_t i = 0; i < sizeof(x); ++i) {
    *zp++ = *xp++;
  }
  return zp;
#endif
}