btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  uint8_t m = x & 0xff;
  *zp++ = (m);
  m = x >> 8 & 0xff;
  *zp++ = (m);
  m = x >> 16 & 0xff;
  *zp++ = (m);
  m = x >> 24 & 0xff;
  *zp++ = (m);
  return zp;
#else
  uint32_t y = htonl(x);
  memcpy(zp, &y, sizeof(y));
  return zp + sizeof(x);
#endif
}