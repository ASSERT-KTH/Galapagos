Variant 1:

void btc_write32be_v1(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  cp = (unsigned char*)&x;
  zp[0] = cp[0];
  zp[1] = cp[1];
  zp[2] = cp[2];
  zp[3] = cp[3];
#else
  zp[0] = (x & 0xff000000) >> 24;
  zp[1] = (x & 0x00ff0000) >> 16;
  zp[2] = (x & 0x0000ff00) >>  8;
  zp[3] = (x & 0x000000ff) >>  0;
#endif
}


Variant 2:

void btc_write32be_v2(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  uint8_t* cp = (uint8_t *)&x;
  for (int i = 0; i < sizeof(uint32_t); i++)
    zp[i] = cp[i];
#else
 for (int i = 0; i < sizeof(uint32_t); i++)
    zp[i] = x >> (8 * (3 - i));
#endif
}


Variant 3:

void btc_write32be_v3(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  zp[0] = (*(((uint8_t*)&x) + 0));
  zp[1] = (*(((uint8_t*)&x) + 1));
  zp[2] = (*(((uint8_t*)&x) + 2));
  zp[3] = (*(((uint8_t*)&x) + 3));
#else
  zp[3] = ((x << 8*0) >> 24) & 0xFF;
  zp[2] = ((x << 8*1) >> 24) & 0xFF;
  zp[1] = ((x << 8*2) >> 24) & 0xFF;
  zp[0] = ((x << 8*3) >> 24) & 0xFF;
#endif
}
