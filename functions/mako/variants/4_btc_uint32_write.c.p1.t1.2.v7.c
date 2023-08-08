
btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  zp[0] = (x >>  0);
  zp[1] = (x >>  8);
  zp[2] = (x >> 16);
  zp[3] = (x >> 24);
  return zp + 4;
#else
  *(uint32_t*)zp = x;
  return zp + sizeof(x);
#endif
}
