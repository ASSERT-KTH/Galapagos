btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  *(zp) = (x >>  0);
  *(zp + 1) = (x >>  8);
  *(zp + 2) = (x >> 16);
  *(zp + 3) = (x >> 24);
  return zp + 4;
#else
  memcpy(zp, &x, sizeof(uint32_t));
  zp += sizeof(uint32_t);
  return zp;
#endif
}