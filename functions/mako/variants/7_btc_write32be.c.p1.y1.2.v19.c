Variant 1:

void btc_write32be(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  *((uint32_t*)zp) = x;
#else
  zp[0] = (uint8_t)(x >> (8*3));
  zp[1] = (uint8_t)(x >> (8*2));
  zp[2] = (uint8_t)(x >> (8*1));
  zp[3] = (uint8_t)(x >> (8*0));
#endif
}


Variant 2:

void btc_write32be(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  *(uint32_t*)zp = x;
#else
  for(int i = 0; i<sizeof(uint32_t); i++)
    zp[i] = (uint8_t)(x >> (8*(sizeof(uint32_t)-1-i)));
#endif
}


Variant 3:

void btc_write32be(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  zp[0] = *((unsigned char*)&x+0);
  zp[1] = *((unsigned char*)&x+1);
  zp[2] = *((unsigned char*)&x+2);
  zp[3] = *((unsigned char*)&x+3);
#else
  zp[0] = (x & 0xff000000) >> 24;
  zp[1] = (x & 0x00ff0000) >> 16;
  zp[2] = (x & 0x0000ff00) >> 8;
  zp[3] = (x & 0x000000ff);
#endif
}
