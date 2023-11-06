btc_write32be(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  for(size_t i=0; i<sizeof(x); ++i) { 
    zp[i] = ((uint8_t*) &x)[i]; 
  } 
#else
  for(int i = 3; i >= 0; --i) { 
    zp[i] = (x & 0xff); 
    x >>= 8; 
  }
#endif
}