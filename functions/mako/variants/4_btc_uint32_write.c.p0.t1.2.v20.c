btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  *zp++ = (x & 0x000000ff);
  *zp++ = (x & 0x0000ff00) >>  8;
  *zp++ = (x & 0x00ff0000) >> 16;
  *zp++ = (x & 0xff000000) >> 24;
  return zp;
#else
  uint8_t *p = (uint8_t *)&x;
  *zp++ = *p++;
  *zp++ = *p++;
  *zp++ = *p++;
  *zp++ = *p++;
  return zp;
#endif
}