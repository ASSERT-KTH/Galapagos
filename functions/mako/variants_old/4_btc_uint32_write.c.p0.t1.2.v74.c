btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  *zp++ = (x >>  0) & 0xff;
  *zp++ = (x >>  8) & 0xff;
  *zp++ = (x >> 16) & 0xff;
  *zp++ = (x >> 24) & 0xff;
  return zp;
#else
  unsigned char temp[4] = {0};
  memcpy(temp, &x, sizeof(x));
  memcpy(zp, temp, sizeof(x));
  return zp + 4;
#endif
}