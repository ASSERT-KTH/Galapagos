btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  *(zp + 0) = (x >> 24);
  *(zp + 1) = (x >> 16);
  *(zp + 2) = (x >>  8);
  *(zp + 3) = (x >>  0);
  return zp + 4;
#else
  uint8_t *bytePtr = (uint8_t*)&x;
  *zp++ = *bytePtr++;
  *zp++ = *bytePtr++;
  *zp++ = *bytePtr++;
  *zp++ = *bytePtr++;
  return zp;
#endif
}