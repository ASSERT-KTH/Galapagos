Variant 1:

void btc_write32be(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  int i; uint8_t *ptr = (uint8_t *)&x; for(i = 0; i < sizeof(x); i++) zp[i] = ptr[i];
#else
  zp[0] = (x & 0xFF000000) >> 24;
  zp[1] = (x & 0x00FF0000) >> 16;
  zp[2] = (x & 0x0000FF00) >> 8;
  zp[3] = (x & 0x000000FF);
#endif
}


Variant 2:

void btc_write32be(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  *((uint32_t*)zp) = x;
#else
  zp[0] = x >> 24;
  zp[1] = (x >> 16) & 0x000000ff;
  zp[2] = (x >> 8) & 0x000000ff; 
  zp[3] = x & 0x000000ff;  
#endif
}


Variant 3:

void btc_write32be(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  memcpy(zp, &x, 4);
#else
  *(zp + 0) = (uint8_t)(x >> 24);
  *(zp + 1) = (uint8_t)(x >> 16);
  *(zp + 2) = (uint8_t)(x >>  8);
  *(zp + 3) = (uint8_t)(x >>  0);
#endif
}
