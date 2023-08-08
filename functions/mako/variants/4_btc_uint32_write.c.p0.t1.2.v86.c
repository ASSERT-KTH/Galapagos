btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  *zp++ = (x & 0xFF);
  x = x >> 8;
  *zp++ = (x & 0xFF);
  x = x >> 8;
  *zp++ = (x & 0xFF);
  x = x >> 8;
  *zp++ = (x & 0xFF);
  return zp;
#else
  uint8_t *px = (uint8_t *)&x;
  for (int i = 0; i < sizeof(x); ++i)
    *zp++ = px[i];
  return zp;
#endif
}