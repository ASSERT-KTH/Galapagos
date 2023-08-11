btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  zp[0] = (x >>  0);
  zp[1] = (x >>  8);
  zp[2] = (x >> 16);
  zp[3] = (x >> 24);
  zp += 4;
  return zp;
#else
  uint32_t *zp32 = (uint32_t*)zp;
  *zp32 = x;
  return zp + 4;
#endif
}