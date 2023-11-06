Variant 1:

void btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  *zp++ = (uint8_t)(x >>  0);
  *zp++ = (uint8_t)(x >>  8);
  *zp++ = (uint8_t)(x >> 16);
  *zp++ = (uint8_t)(x >> 24);
#else
  uint8_t* xp = (uint8_t*)&x;
  *zp++ = *xp++;
  *zp++ = *xp++;
  *zp++ = *xp++;
  *zp++ = *xp++;
#endif
}


Variant 2:

void btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  zp[0]= (uint8_t)(x >>  0);
  zp[1]= (uint8_t)(x >>  8);
  zp[2]= (uint8_t)(x >> 16);
  zp[3]= (uint8_t)(x >> 24);
#else
  uint32_t* xp = (uint32_t*)zp;
  *xp = x;
#endif
}


Variant 3:

void btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  zp[0] = (x >>  0) & 0xFF;
  zp[1] = (x >>  8) & 0xFF;
  zp[2] = (x >> 16) & 0xFF;
  zp[3] = (x >> 24) & 0xFF;
#else
  zp[3] = x & 0xFF;
  zp[2] = (x >>  8) & 0xFF;
  zp[1] = (x >> 16) & 0xFF;
  zp[0] = (x >> 24) & 0xFF;
#endif
}


Variant 4:

void btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  *zp++ = x & 0xFF;
  *zp++ = (x >>  8) & 0xFF;
  *zp++ = (x >> 16) & 0xFF;
  *zp++ = (x >> 24) & 0xFF;
#else
  unsigned char* xp = (unsigned char*)&x;
  *zp++ = *xp++;
  *zp++ = *xp++;
  *zp++ = *xp++;
  *zp++ = *xp++;
#endif
}
