void btc_write32be(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  memcpy(zp, &x, sizeof(x));
#else
  for(int i = 3; i >= 0; i--) 
  {
     zp[i] = (uint8_t)x;
     x >>= 8;
  }
#endif
}