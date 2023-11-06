1. 

btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  zp[0] = (x >>  0);
  zp[1] = (x >>  8);
  zp[2] = (x >> 16);
  zp[3] = (x >> 24);
  return zp + 4;
#else
  memcpy(zp, &x, sizeof(x));
  return zp + 4;
#endif
}


2. 

btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  for (int i = 0; i < 4; i++) {
    zp[i] = x >> (8 * i);
  }
#else
  memcpy(zp, &x, sizeof(x));
#endif
  return zp + 4;
}


3. 

btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  uint8_t *zp_end = zp + 4;
  while (zp != zp_end) {
    *zp = x;
    x >>= 8;
    zp++;
  }
#else
  memcpy(zp, &x, sizeof(x));
  zp += 4;
#endif
  return zp;
}


4. 

btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  for (int i = 0; i < 4; i++) {
    zp[i] = (uint8_t)(x >> (8 * i));
  }
#else
  *(uint32_t*)zp = x;
  zp += 4;
#endif
  return zp;
}
