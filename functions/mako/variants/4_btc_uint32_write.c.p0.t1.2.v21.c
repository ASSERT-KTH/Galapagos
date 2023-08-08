btc_uint32_write(uint8_t *zp, uint32_t y) {
#if defined(BTC_BIGENDIAN)
  *zp++ = (y >>  0);
  *zp++ = (y >>  8);
  *zp++ = (y >> 16);
  *zp++ = (y >> 24);
  return zp;
#else
  uint32_t x = y;
  memcpy(zp, &x, sizeof(x));
  return zp + 4;
#endif
}