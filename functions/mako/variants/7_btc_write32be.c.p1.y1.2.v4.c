1)

void btc_write32be(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  *(uint32_t *)zp = x;
#else
  zp[3] = x & 0xFF;
  zp[2] = (x >> 8) & 0xFF;
  zp[1] = (x >> 16) & 0xFF;
  zp[0] = (x >> 24) & 0xFF;
#endif
}


2)

void btc_write32be(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  uint32_t* p = (uint32_t*)zp;
  *p = x;
#else
  for(int i = 0; i < 4; ++i) {
    zp[i] = (x >> ((3-i)*8));
  }  
#endif
}


3)

void btc_write32be(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  *(uint32_t *)zp = x;
#else
  zp[0] = x >> 24;             
  zp[1] = x >> 16;                       
  zp[2] = x >> 8;                     
  zp[3] = x;                     
#endif
}
