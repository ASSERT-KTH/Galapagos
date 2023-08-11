btc_write32be(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  if(zp!=NULL && sizeof(x)>=4) {
      *(uint32_t*)zp = x;
  }
#else
  unsigned int i;
  for(i=0; i<4; ++i)
    zp[i] = (x >> (8*(3-i)));
#endif 
}