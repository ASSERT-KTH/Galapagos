
void btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  *zp++ = (x >> 24) & 0xFF;
  *zp++ = (x >> 16) & 0xFF;
  *zp++ = (x >>  8) & 0xFF;
  *zp++ = (x >>  0) & 0xFF;
  return zp;
#else
  *zp++ = x & 0xFF;
  *zp++ = (x >>  8) & 0xFF;
  *zp++ = (x >> 16) & 0xFF;
  *zp++ = (x >> 24) & 0xFF;
  return zp + 4;
#endif
}



void btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  zp[0] = (x >> 24) & 0xFF;
  zp[1] = (x >> 16) & 0xFF;
  zp[2] = (x >> 8) & 0xFF;
  zp[3] = x & 0xFF;
  return zp + 4;
#else
  zp[0] = x & 0xFF;
  zp[1] = (x >> 8) & 0xFF;
  zp[2] = (x >> 16) & 0xFF;
  zp[3] = (x >> 24) & 0xFF;
  return zp + 4;
#endif
}



void btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  *zp = (uint8_t)(x >> 24); zp++;
  *zp = (uint8_t)(x >> 16); zp++;
  *zp = (uint8_t)(x >>  8); zp++;
  *zp = (uint8_t)(x); zp++;
  return zp;
#else
  *zp = (uint8_t)(x); zp++;
  *zp = (uint8_t)(x >>  8); zp++;
  *zp = (uint8_t)(x >> 16); zp++;
  *zp = (uint8_t)(x >> 24); zp++;
  return zp;
#endif
}
