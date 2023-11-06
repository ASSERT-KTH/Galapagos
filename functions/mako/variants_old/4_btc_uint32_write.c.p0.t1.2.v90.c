btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  *zp++ = (x >> 24);
  *zp++ = (x >> 16);
  *zp++ = (x >>  8);
  *zp++ = (x >>  0);
  return zp;
#else
  for (size_t i = 0; i < sizeof(x); ++i)
  {
     memcpy(zp + i, (uint8_t*)&x + i, 1);
  }
  return zp + sizeof(x);
#endif
}