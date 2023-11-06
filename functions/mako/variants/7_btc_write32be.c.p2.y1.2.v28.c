void btc_write32be(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  for(size_t i=0; i<sizeof(x); ++i) {
      zp[i] = ((uint8_t*)&x)[i];
  }
#else
  unsigned shift[] = {24, 16, 8, 0};
  for(int i=0; i < 4; i++){
    zp[i] = x >> shift[i];
  }
#endif
}