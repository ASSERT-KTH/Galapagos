Variant 1:


btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  uint32_t num = 0;
  for (int i = 0; i < 4; ++i) {
    num |= ((uint32_t)xp[i] <<  (i * 8));
  }
  return num;
#else
  uint32_t z;
  memmove(&z, xp, sizeof(z));
  return z;
#endif
}


Variant 2:


btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  return ((uint32_t)xp[3] <<  24) 
       | ((uint32_t)xp[2] <<  16)   
       | ((uint32_t)xp[1] <<  8)
       | ((uint32_t)xp[0] <<  0);
#else
  union
  {
    uint32_t n;
    uint8_t bytes[sizeof(uint32_t)];
  }y;
  y.bytes[0] = xp[0];
  y.bytes[1] = xp[1];
  y.bytes[2] = xp[2];
  y.bytes[3] = xp[3];
  return y.n;
#endif
}


Variant 3:


btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  int shiftVal = 0
  uint32_t toReturn = 0;
  for(int i=0;i<4;i++ , shiftVal+=8 ){
    toReturn |=  ((uint32_t)xp[i] << shiftVal);
  }
  return toReturn;
#else
  uint32_t z = 0;
  z = xp[0] | xp[1] << 8 | xp[2] << 16 | xp[3] << 24;
  return z;
#endif
}
