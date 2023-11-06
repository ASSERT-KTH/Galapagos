btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  zp[0] = (x >>  0);
  zp[1] = (x >>  8);
  zp[2] = (x >> 16);
  zp[3] = (x >> 24);
  return zp + 4;
#else
  uint8_t* x_ptr = (uint8_t*)&x;
  for(int i=0; i<4; i++)
    *(zp+i) = *(x_ptr + i);
  return zp + 4;
#endif
}
---------------

btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  uint32_t *yz = (uint32_t*)zp;
  *yz = (((x >> 24) & 0xff) | ((x << 8) & 0xff0000) | ((x >> 8) & 0xff00) | ((x << 24) & 0xff000000));
  return zp + 4;
#else
  uint32_t *yz = (uint32_t*)zp;
  *yz = x;
  return zp + 4;
#endif
}
---------------

btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  zp = (uint8_t*)(&x);
  zp[0] = (x >>  0);
  zp[1] = (x >>  24);
  zp[2] = (x >>  16);
  zp[3] = (x >>  8);
  return zp + 4;
#else 
  *((uint32_t*)zp) = x;
  return zp + 4;
#endif
}