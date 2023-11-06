Variant 1:


void btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  uint8_t* cp = (uint8_t*)&x;

  zp[0] = cp[0];
  zp[1] = cp[1];
  zp[2] = cp[2];
  zp[3] = cp[3];

  return zp + 4;
#else
  uint8_t* cp = (uint8_t*)&x;

  zp[0] = cp[0];
  zp[1] = cp[1];
  zp[2] = cp[2];
  zp[3] = cp[3];

  return zp + 4;
#endif
}


Variant 2:


void btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  *(zp++) = ((x) & 0xFF);
  *(zp++) = ((x >> 8) & 0xFF);
  *(zp++) = ((x >> 16) & 0xFF);
  *(zp++) = ((x >> 24) & 0xFF);
    
  return zp;
#else
  zp[0] = x & 0xFF;
  zp[1] = (x >> 8) & 0xFF;
  zp[2] = (x >> 16) & 0xFF;
  zp[3] = (x >> 24) & 0xFF;

  return zp + 4;
#endif
}
