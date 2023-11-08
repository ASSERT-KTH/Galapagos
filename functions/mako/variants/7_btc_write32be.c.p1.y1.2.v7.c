Variant 1:

void btc_write32be(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  int i;
  for(i = 0; i < sizeof(x); i++) {
    zp[i] = ((uint8_t*)(&x))[i];
  }
#else
  zp[0] = (uint8_t)((x & 0xFF000000) >> 24);
  zp[1] = (uint8_t)((x & 0x00FF0000) >> 16);
  zp[2] = (uint8_t)((x & 0x0000FF00) >>  8);
  zp[3] = (uint8_t)(x & 0x000000FF);
#endif
}


Variant 2:

void btc_write32be(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  int8_t *k = (int8_t *)&x;
  zp[0] = k[0];
  zp[1] = k[1];
  zp[2] = k[2];
  zp[3] = k[3];
#else
  zp[0] = (x >> 24) & 0xFF;
  zp[1] = (x >> 16) & 0xFF;
  zp[2] = (x >>  8) & 0xFF;
  zp[3] = (x >>  0) & 0xFF;
#endif
}


Variant 3:

void btc_write32be(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  *(uint32_t *) zp = x;
#else
  zp[0] = x >> 24;
  zp[1] = (x << 8)  >> 24;
  zp[2] = (x << 16) >> 24;
  zp[3] = (x << 24) >> 24;
#endif
}