1)
btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  unsigned int result  = 0;
  result |= xp[0];
  result |= xp[1] << 8;
  result |= xp[2] << 16;
  result |= xp[3] << 24;
#else
  uint32_t z;
  memmove(&z, xp, sizeof(z));
  return z;
#endif
  return result;
}

2)
btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  return (xp[0])
       + (xp[1] <<  8)
       + (xp[2] << 16)
       + (xp[3] << 24);
#else
  uint32_t z = 0;
  z = xp[0] 
    | (xp[1] <<  8) 
    | (xp[2] << 16) 
    | (xp[3] << 24);
  return z;
#endif
}

3)
btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  uint32_t ret = 0;
  int i;
  for(i=0; i<4; i++) {
      ret = (ret << 8) | xp[i];
  }
  return ret;
#else
  uint32_t z;
  z = *(uint32_t*)xp;
  return z;
#endif
}