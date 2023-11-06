btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  *zp++ = (x >>  24) & 0xff;
  *zp++ = (x >>  16) & 0xff;
  *zp++ = (x >>  8) & 0xff;
  *zp++ = (x >>  0) & 0xff;
  return zp;
#else
  zp[0] = x & 0xff;
  zp[1] = (x >> 8) & 0xff;
  zp[2] = (x >> 16) & 0xff;
  zp[3] = (x >> 24) & 0xff;
  return zp + 4;
#endif
}