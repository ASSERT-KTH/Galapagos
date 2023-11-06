Variant 1:

void btc_write32be(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  *(uint32_t*)zp = x;
#else
  zp[0] = (x & 0xff000000) >> 24;
  zp[1] = (x & 0x00ff0000) >> 16;
  zp[2] = (x & 0x0000ff00) >>  8;
  zp[3] = (x & 0x000000ff);
#endif
}


Variant 2:

void btc_write32be(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  uint32_t *p = (uint32_t*)zp;
  *p = x;
#else
  zp[0] = (unsigned char)((x & 0xFF000000) >> 24);
  zp[1] = (unsigned char)((x & 0x00FF0000) >> 16);
  zp[2] = (unsigned char)((x & 0x0000FF00) >>  8);
  zp[3] = (unsigned char)(x&0xFF);
#endif
}


Variant 3:

void btc_write32be(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  int i;
  for(i = 0; i < sizeof(uint32_t); ++i) {
    zp[i] = ((uint8_t*)&x)[i];
  }
#else
  zp[0] = x >> 24;
  zp[1] = x >> 16;
  zp[2] = x >>  8;
  zp[3] = x;
#endif
}
