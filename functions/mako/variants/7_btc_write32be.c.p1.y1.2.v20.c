Variant 1:


void btc_write32be(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  zp[0] = *((uint8_t*)&x + 3);  
  zp[1] = *((uint8_t*)&x + 2); 
  zp[2] = *((uint8_t*)&x + 1);
  zp[3] = *((uint8_t*)&x);
#else
  zp[0] = (uint8_t)(x >> 24);
  zp[1] = (uint8_t)(x >> 16);
  zp[2] = (uint8_t)(x >> 8);
  zp[3] = (uint8_t)(x);
#endif
}


Variant 2:


void btc_write32be(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  memcpy(zp, &x, sizeof(x));
#else
  zp[0] = (x & 0xFF000000) >> 24;
  zp[1] = (x & 0x00FF0000) >> 16;
  zp[2] = (x & 0x0000FF00) >> 8;
  zp[3] = (x & 0x000000FF);
#endif
}
  

Variant 3:


void btc_write32be(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  for(int idx = 0; idx < sizeof(x); idx++) {
      zp[idx] = *((uint8_t*)&x + sizeof(x) - idx - 1);
  }
#else
  for(int idx = 0; idx < sizeof(x); idx++) {
      zp[idx] = x >> (idx * 8);
      x >>= 8;
  }
#endif
}
