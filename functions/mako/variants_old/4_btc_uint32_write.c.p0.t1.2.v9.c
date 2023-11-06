btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  *zp++ = (x >> 24) & 0xFF;
  *zp++ = (x >> 16) & 0xFF;
  *zp++ = (x >>  8) & 0xFF;
  *zp++ = (x >>  0) & 0xFF;
  return zp;
#else
  *(uint32_t*)zp = x;
  return zp + 4;
#endif
}