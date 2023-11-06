btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  *zp = (x >>  0);
  ++zp;
  *zp = (x >>  8);
  ++zp;
  *zp = (x >> 16);
  ++zp;
  *zp = (x >> 24);
  ++zp;
  return zp;
#else
  for(size_t i = 0; i < sizeof(x); i++) {
    zp[i] = ((x >> (8*i)) & 0xff);
  }
  return zp + 4;
#endif
}