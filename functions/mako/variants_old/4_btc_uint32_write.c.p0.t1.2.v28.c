btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  *zp++ = ((x & 0x000000FF) >>  0);
  *zp++ = ((x & 0x0000FF00) >>  8);
  *zp++ = ((x & 0x00FF0000) >> 16);
  *zp++ = ((x & 0xFF000000) >> 24);
  return zp;
#else
  uint32_t tempX = x;
  memcpy(zp, &tempX, sizeof(tempX));
  return zp + sizeof(tempX);
#endif
}