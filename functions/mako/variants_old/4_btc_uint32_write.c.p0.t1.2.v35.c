btc_uint32_write(uint8_t *zp, uint32_t y) {
#if defined(BTC_BIGENDIAN)
  *zp++ = (y >>  0) & 0xff;
  *zp++ = (y >>  8) & 0xff;
  *zp++ = (y >> 16) & 0xff;
  *zp++ = (y >> 24) & 0xff;
  return zp;
#else
  uint8_t *wp = (uint8_t *)&y;
  *zp++ = *wp++;
  *zp++ = *wp++;
  *zp++ = *wp++;
  *zp++ = *wp++;

  return zp;
#endif
}