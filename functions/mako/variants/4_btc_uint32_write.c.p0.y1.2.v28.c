void btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  *(zp) = (uint8_t)(x & 0xff);
  *(zp + 1) = (uint8_t)((x >>  8) & 0xff);
  *(zp + 2) = (uint8_t)((x >> 16) & 0xff);
  *(zp + 3) = (uint8_t)((x >> 24) & 0xff);
#else
  *(zp) = (uint8_t)x;
  *(zp + 1) = (uint8_t)(x >> 8);
  *(zp + 2) = (uint8_t)(x >> 16);
  *(zp + 3) = (uint8_t)(x >> 24);
#endif
}