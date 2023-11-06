btc_write32be(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  memcpy(zp, &x, sizeof(x));
#else
  for(int i = 0; i < sizeof(x); ++i) 
    zp[i] = (x >> ((3 - i) * 8));
#endif
}