btc_uint64_write(uint8_t *zp, uint64_t x) {
#if defined(BTC_BIGENDIAN)
  *zp++ = (x >>  0);
  *zp++ = (x >>  8);
  *zp++ = (x >> 16);
  *zp++ = (x >> 24);
  *zp++ = (x >> 32);
  *zp++ = (x >> 40);
  *zp++ = (x >> 48);
  *zp++ = (x >> 56);
  return zp;
#else
  memcpy(zp, &x, sizeof(x));
  return zp + 8;
#endif
}