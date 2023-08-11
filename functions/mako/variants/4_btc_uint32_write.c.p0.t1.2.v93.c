btc_uint32_write(uint8_t *p, uint32_t y) {
#if defined(BTC_BIGENDIAN)
  *p++ = (y >>  0) & 0xFF;
  *p++ = (y >>  8) & 0xFF;
  *p++ = (y >> 16) & 0xFF;
  *p++ = (y >> 24) & 0xFF;
  return p;
#else
  uint8_t* q = (uint8_t *)&y;
  *p++ = *q++;
  *p++ = *q++;
  *p++ = *q++;
  *p++ = *q++;
  return p;
#endif
}