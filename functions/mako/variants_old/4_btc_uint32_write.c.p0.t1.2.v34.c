btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  *zp++ = (x >> 24);
  *zp++ = (x >> 16);
  *zp++ = (x >>  8);
  *zp++ = (x >>  0);
  return zp;
#else
  uint8_t *temp = zp;
  *_temp++ = (x >> 0) & 0xFF;
  *_temp++ = (x >> 8) & 0xFF;
  *_temp++ = (x >> 16) & 0xFF;
  *_temp++ = (x >> 24) & 0xFF;
  return zp + 4;
#endif
}