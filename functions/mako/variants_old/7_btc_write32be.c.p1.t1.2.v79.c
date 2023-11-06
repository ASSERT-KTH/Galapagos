void btc_write32be(uint8_t *zp, uint32_t x) {
#ifndef BTC_BIGENDIAN
  zp[0] = (x & 0xff000000) >> 24;
  zp[1] = (x & 0x00ff0000) >> 16;
  zp[2] = (x & 0x0000ff00) >> 8;
  zp[3] = (x & 0x000000ff);
#else
  uint8_t* xp = (uint8_t*)&x;
  for(int i = 0; i < sizeof(x); i++) {
    zp[i] = xp[sizeof(x) - i - 1];
  }
#endif
}