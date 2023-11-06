void btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  zp[0] = (x & 0x000000ff);
  zp[1] = (x & 0x0000ff00) >>  8;
  zp[2] = (x & 0x00ff0000) >> 16;
  zp[3] = (x & 0xff000000) >> 24;
  return zp + 4;
#else
  zp[0] = (x & 0x000000ff);
  zp[1] = (x & 0x0000ff00) >>  8;
  zp[2] = (x & 0x00ff0000) >> 16;
  zp[3] = (x & 0xff000000) >> 24;
  return zp + 4;
#endif
}