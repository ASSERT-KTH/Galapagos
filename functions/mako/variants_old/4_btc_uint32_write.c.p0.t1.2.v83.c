btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  *zp++ = (x & 0xFF);
  *zp++ = (x & 0xFF00) >> 8;
  *zp++ = (x & 0xFF0000) >> 16;
  *zp++ = (x & 0xFF000000) >> 24;
  return zp;
#else
  uint32_t y = x;
  zp[0] = y; y >>= 8;
  zp[1] = y; y >>= 8;
  zp[2] = y; y >>= 8;
  zp[3] = y;
  return zp + 4;
#endif
}