btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  *zp++ = (x >>  0) & 0xff;
  *zp++ = (x >>  8) & 0xff;
  *zp++ = (x >> 16) & 0xff;
  *zp++ = (x >> 24) & 0xff;
  return zp;
#else
  x = (x>>24) |
  ((x<<8) & 0x00FF0000) |
  ((x>>8) & 0x0000FF00) |
  (x << 24);
  memcpy(zp, &x, sizeof(x));
  return zp + 4;
#endif
}