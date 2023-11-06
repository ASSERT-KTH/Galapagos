Variant 1:

void btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  zp[3] = x;
  zp[2] = x >> 8;
  zp[1] = x >> 16;
  zp[0] = x >> 24;
#else
  zp[0] = x;
  zp[1] = x >> 8;
  zp[2] = x >> 16;
  zp[3] = x >> 24;
#endif
}

Variant 2:

void btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  int shift;
  for (shift = 24; shift >= 0; shift -= 8) {
    *zp++ = (uint8_t) ((x >> shift) % 256);
  }
#else
  int shift;
  for (shift = 0; shift <= 24; shift += 8) {
    *zp++ = (uint8_t) (x >> shift % 256);
  }
#endif
}

Variant 3:

void btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  *zp++ = x & 0xFF;
  *zp++ = (x >> 8) & 0xFF;
  *zp++ = (x >> 16) & 0xFF;
  *zp++ = (x >> 24) & 0xFF;        
#else
  zp[0] = x & 0xFF;
  zp[1] = (x >> 8) & 0xFF;
  zp[2] = (x >> 16) & 0xFF;
  zp[3] = (x >> 24) & 0xFF;
#endif   
}
