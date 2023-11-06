Variant 1:

void btc_write32be(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  *((uint32_t*)zp) = x;
#else
  zp[0] = (x >> 24) & 0xFF;
  zp[1] = (x >> 16) & 0xFF;
  zp[2] = (x >> 8) & 0xFF;
  zp[3] = x & 0xFF;
#endif
}


 Variant 2:


void btc_write32be(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  zp[0] = ((char *)&x)[0];
  zp[1] = ((char *)&x)[1];
  zp[2] = ((char *)&x)[2];
  zp[3] = ((char *)&x)[3];
#else
  zp[0] = (x & 0xFF000000) >> 24;
  zp[1] = (x & 0x00FF0000) >> 16;
  zp[2] = (x & 0x0000FF00) >> 8;
  zp[3] = (x & 0x000000FF) >> 0;
#endif
}


Variant 3: 


void btc_write32be(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  *(uint32_t*)zp = x;
#else
  union { uint32_t v; uint8_t b[4]; } u;
  u.v = x;
  zp[0] = u.b[3];
  zp[1] = u.b[2];
  zp[2] = u.b[1];
  zp[3] = u.b[0];
#endif
}
