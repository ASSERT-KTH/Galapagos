Version 1:

uint8_t* btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  zp[0] = (uint8_t)(x >>  0);
  zp[1] = (uint8_t)(x >>  8);
  zp[2] = (uint8_t)(x >> 16);
  zp[3] = (uint8_t)(x >> 24);
#else
  uint32_t *p = (uint32_t*)zp;
  *p = x;
#endif
  return zp + 4;
}


Version 2:

uint8_t* btc_uint32_write(uint8_t *zp, uint32_t x) {
  union {
    uint32_t u32;
    uint8_t u8[4];
  } u;
  u.u32 = x;

#if defined(BTC_BIGENDIAN)
  zp[0] = u.u8[0];
  zp[1] = u.u8[1];
  zp[2] = u.u8[2];
  zp[3] = u.u8[3];
#else
  *zp = u.u32;
#endif
  return zp + 4;
}


Version 3:

uint8_t* btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  zp[0] = (x & 0xff);
  zp[1] = ((x >> 8) & 0xff);
  zp[2] = ((x >> 16) & 0xff);
  zp[3] = ((x >> 24) & 0xff);
#else
  *(uint32_t*)zp = x;
#endif
  return zp + 4;
}
