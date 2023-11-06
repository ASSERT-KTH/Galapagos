Variant 1:


void btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  zp[0] = x;
  zp[1] = x >>  8;
  zp[2] = x >> 16;
  zp[3] = x >> 24;
#else
  memcpy(zp, &x, 4);
#endif
  zp += 4;
}

Variant 2:

uint8_t* btc_uint32_write(uint8_t *zp, uint32_t x) { 
#if defined(BTC_BIGENDIAN) 
  for (int i = 0; i < 4; i++, zp++)
    *zp = (uint8_t)(x >> 8 * i); 
#else 
  ((uint32_t*) zp)[0] = x;
  zp += sizeof(x);
#endif 
  return zp; 
}

Variant 3:


uint8_t* btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  for(int i = 0; i < 4; ++i) {
    *zp = (x >> (i << 3)) & 0xFF;
    ++zp;
  }
#else
  uint32_t *zp32 = (uint32_t *)zp;
  *zp32 = x;
  zp += sizeof(uint32_t);
#endif
  return zp;
}
