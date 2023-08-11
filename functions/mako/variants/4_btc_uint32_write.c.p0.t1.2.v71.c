btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  *zp = (x >>  0);
  zp++;
  *zp = (x >>  8);
  zp++;
  *zp = (x >> 16);
  zp++;
  *zp = (x >> 24);
  zp++;
#else
  uint8_t *tmp = (uint8_t*)&x;
  *zp = *tmp;
  tmp++;
  zp++;
  *zp = *tmp;
  tmp++;
  zp++;
  *zp = *tmp;
  tmp++;
  zp++;
  *zp = *tmp;
#endif
  return zp;
}