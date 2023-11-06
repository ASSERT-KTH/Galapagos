Variant 1:

void btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  *(zp + 0) = (uint8_t)(x >>  0);
  *(zp + 1) = (uint8_t)(x >>  8);
  *(zp + 2) = (uint8_t)(x >> 16);
  *(zp + 3) = (uint8_t)(x >> 24);
#else
  memcpy(zp, &x, sizeof(x));
  zp += 4;
#endif
}


Variant 2:

void btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  zp[0] = (x >>  0);
  zp[1] = (x >>  8);
  zp[2] = (x >> 16);
  zp[3] = (x >> 24);
#else
  uint32_t *zp_casted = (uint32_t*) zp;
  *zp_casted = x;
  zp += sizeof(uint32_t);
#endif
}


Variant 3:

void btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  for(int i = 0; i < 4; i++) {
    *(zp + i) = (uint8_t)(x >>  (8 * i));
  }
#else
  uint32_t *zp_casted = (uint32_t*) zp;
  *zp_casted = x;
  zp += sizeof(uint32_t);
#endif
}
