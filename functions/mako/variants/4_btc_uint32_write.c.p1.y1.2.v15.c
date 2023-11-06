Version 1:

void btc_uint32_write(uint8_t *zp, uint32_t x) {
  zp[0] = (x >>  0) & 0xff;
  zp[1] = (x >>  8) & 0xff;
  zp[2] = (x >> 16) & 0xff;
  zp[3] = (x >> 24) & 0xff;
    
#if defined(BTC_BIGENDIAN)
return zp += 4;
#else
zp += sizeof(x);
return zp;
#endif
}

  
Version 2:

void btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  *zp = (x >>  0);
  *(zp+1) = (x >>  8);
  *(zp+2) = (x >> 16);
  *(zp+3) = (x >> 24);
  return zp+=4;
#else
  for (int i = 0; i < sizeof(uint32_t); i++) {
    *(zp + i)= *(((uint8_t*)&x) + i);
  }
  return zp+=4;
#endif
}


Version 3:

void btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  for (unsigned i = 0; i < sizeof(x); i++) {
      zp[i] = x >> (8 * i);
  }
  return zp += 4;
#else
  memcpy(zp, &x, sizeof(x));
  return zp += sizeof(uint32_t);
#endif
}
