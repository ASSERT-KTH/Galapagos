btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  *zp++ = (uint8_t)(x & 0xff);
  *zp++ = (uint8_t)((x >>  8) & 0xff);
  *zp++ = (uint8_t)((x >> 16) & 0xff);
  *zp++ = (uint8_t)(x >> 24);
  return zp;
#else
  zp[0] = x & 0xFF;
  zp[1] = (x >> 8) & 0xFF;
  zp[2] = (x >> 16) & 0xFF;
  zp[3] = (x >> 24) & 0xFF;
  return zp + sizeof(x);
#endif
}