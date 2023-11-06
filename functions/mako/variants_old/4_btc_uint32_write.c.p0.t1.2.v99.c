btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  for (int i = 0; i < 32; i += 8) { 
      *zp++ = (x >> i);
  }
  return --zp; 
#else
  for(int i = 0; i < sizeof(x); ++i) {
      zp[i] = ((uint8_t* )&x)[i];
  }
  return zp + sizeof(x);
#endif
}