void btc_write32be(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  char* ptr = (char*)&x;
  for(int i=0; i<sizeof(x); i++) {
    zp[i] = ptr[i];
  }
#else
  for (int i=0; i<4; i++) {
    zp[i] = (x >> (8 * (3 - i)));
  }
#endif
}