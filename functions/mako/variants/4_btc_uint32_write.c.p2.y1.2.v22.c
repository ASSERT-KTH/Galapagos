btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  *zp++ = (x & 0xff);
  *zp++ = ((x >>  8) & 0xff);
  *zp++ = ((x >> 16) & 0xff);
  *zp++ = ((x >> 24) & 0xff);
  return zp;
#else
  *zp++ = x; x>>=8;
  *zp++ = x; x>>=8;
  *zp++ = x; x>>=8;
  *zp++ = x;
  return zp - 4;
#endif
}