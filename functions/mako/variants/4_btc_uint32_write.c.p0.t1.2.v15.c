btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  *zp++ = (x & 0xFF);
  x >>= 8;
  *zp++ = (x & 0xFF);
  x >>= 8;
  *zp++ = (x & 0xFF);
  x >>= 8;
  *zp++ = (x & 0xFF);
  return zp;
#else
  for (int i = 0; i < sizeof(x); i++) {
    *zp++ = ((x >> (i * 8)) & 0xFF);
  }
  return zp;
#endif
}