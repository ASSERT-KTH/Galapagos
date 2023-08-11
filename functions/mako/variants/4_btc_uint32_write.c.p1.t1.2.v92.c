uint8_t* btc_uint32_write(uint8_t* zp, uint32_t x) {   
#if defined(BTC_BIGENDIAN)
  zp[0]  = x  & 0xff;
  zp[1]  = (x >>  8) & 0xff;
  zp[2]  = (x >> 16) & 0xff; 
  zp[3]  = (x >> 24) & 0xff;
  return zp + 4;
#else
  uint8_t* xByte = (uint8_t*)&x;
  for(size_t i = 0; i < sizeof(x); ++i)
  {
      zp[i] = xByte[i];
  }  
  return zp + 4;
#endif   
}