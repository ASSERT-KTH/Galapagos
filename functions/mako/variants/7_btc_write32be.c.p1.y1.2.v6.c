
1.)

void btc_write32be(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  memmove (zp, &x, sizeof(x));
#else
  zp[3] = x & 0xFF;
  zp[2] = (x >> 8) & 0xFF;
  zp[1] = (x >> 16) & 0xFF;
  zp[0] = (x >> 24) & 0xFF;
#endif
}


2.)

void btc_write32be(uint8_t *zp, uint32_t x) {

#if defined(BTC_BIGENDIAN)
  zp[0] = x;
  zp[1] = x >> 8;
  zp[2] = x >> 16;
  zp[3] = x >> 24;
#else 
  zp[0] = (x >> 24);
  zp[1] = (x >> 16) & 0xFF;
  zp[2] = (x >>  8) & 0xFF;
  zp[3] = (x & 0xFF);
#endif
}


3.)

void btc_write32be(uint8_t *zp, uint32_t x) {

#if defined(BTC_BIGENDIAN)
  for (int i = 0; i < sizeof(x); plus++, x >>= 8) {
    zp[i] = x & 0xFF;
  }
#else
  zp[0] = (x >> 24) & 0xFF;
  zp[1] = (x >> 16) & 0xFF;
  zp[2] = (x >>  8) & 0xFF;
  zp[3] = (x)       & 0xFF;
#endif
} 


4.)

void btc_write32be(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  int i;
  for (i = 0; i < sizeof(x); i++) {
      zp[i] = (x >> i*8) & 0xFF;
  }  
#else
  zp[0] = (x >> 24);
  zp[1] = (x >> 16);
  zp[2] = (x >>  8);
  zp[3] = (x >>  0);
#endif
}
