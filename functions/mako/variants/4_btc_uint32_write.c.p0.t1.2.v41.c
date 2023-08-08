btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  *zp++ = (uint8_t)(x >>  0);
  *zp++ = (uint8_t)(x >>  8);
  *zp++ = (uint8_t)(x >> 16);
  *zp++ = (uint8_t)(x >> 24);
  *zp = 0;
  return zp;
#else
  memcpy(zp, &x, sizeof(x));
  *(zp + 4) = 0;
  return zp + 4;
#endif
}