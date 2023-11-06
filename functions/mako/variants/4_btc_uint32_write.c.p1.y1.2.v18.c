Variant 1:

uint8_t* btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  *zp++ = x & 0xFF;
  *zp++ = (x >> 8) & 0xFF;
  *zp++ = (x >> 16) & 0xFF;
  *zp++ = (x >> 24) & 0xFF;
  return zp;
#else
  size_t i;
  for(i = 0; i < sizeof(x); i++) {
    *(zp+i) = *((uint8_t*)&x + i);
  }
  return zp + 4;
#endif
}


Variant 2:

uint8_t* btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  zp[0] = (x >> 0);
  zp[1] = (x >> 8);
  zp[2] = (x >> 16);
  zp[3] = (x >> 24);
  return zp + 4;
#else
  *((uint32_t*)zp) = x;
  return zp + 4;
#endif
}


Variant 3:

uint8_t* btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  int shift;
  for(shift = 0; shift < 32; shift += 8) {
    *zp++ = (x >> shift);
  }
  return zp;
#else
  uint32_t* p = (uint32_t*)zp;
  *p = x;
  return (uint8_t*)(p + 1);
#endif
}


Variant 4:

uint8_t* btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  int i;
  for (i = 0; i < 4; ++i) {
      zp[i] = (x >> (i * 8));
  }
  return zp + 4;
  
#else
  uint32_t* px = (uint32_t*)zp;
  *px = x;
  return (uint8_t*)(px+1);
#endif
}
