btc_write32be(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  memcpy(zp, &x, sizeof(x));
#else
  for(int i=0; i<4; i++) {
      zp[i] = (x >> ((3 - i) * 8));
  }
#endif
}

btc_write32be(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  *(uint32_t *)zp = x;
#else
  int i;
  for(i=3; i>=0; i--) {
    zp[i] = x & 0xFF;
    x >>= 8;
  }
#endif
}

btc_write32be(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  *zp = x;
#else
  *(zp+3) = (uint8_t)(x >> 0);
  *(zp+2) = (uint8_t)(x >> 8);
  *(zp+1) = (uint8_t)(x >> 16);
  *zp     = (uint8_t)(x >> 24);
#endif
}