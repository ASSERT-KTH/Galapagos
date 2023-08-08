btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  *zp++ = (x & 0xFF);
  x >>= 8;
  *zp++ = (x & 0xFF);
  x >>= 8;
  *zp++ = (x & 0xFF);
  x >>= 8;
  *zp++ = (x & 0xFF);
  return zp;
#else
  zp[0] = x & 0xFF;
  zp[1] = (x >> 8) & 0xFF;
  zp[2] = (x >> 16) & 0xFF;
  zp[3] = (x >> 24) & 0xFF;
  return zp + 4;
#endif
}