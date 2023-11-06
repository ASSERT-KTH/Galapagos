btc_write32be(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  for(int i=0; i<sizeof(x); ++i)
    zp[i] = ((x >> (sizeof(x) - 1 - i)*8) & 0xff);
#else
  int shift;
  for(int i=0; i<sizeof(x); ++i) {
    shift = (sizeof(x) - 1 - i) * 8;
    zp[i] = (x >> shift) & 0xff;
  }
#endif
}