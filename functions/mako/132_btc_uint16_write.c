btc_uint16_write(uint8_t *zp, uint16_t x) {
#if defined(BTC_BIGENDIAN)
  *zp++ = (x >> 0);
  *zp++ = (x >> 8);
  return zp;
#else
  memcpy(zp, &x, sizeof(x));
  return zp + 2;
#endif
}