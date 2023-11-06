btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  *zp++ = (uint8_t)(x & 0xFF);
  *zp++ = (uint8_t)((x >> 8) & 0xFF);
  *zp++ = (uint8_t)((x >> 16) & 0xFF);
  *zp++ = (uint8_t)((x >> 24) & 0xFF);
  return zp;
#else
  zp[0] = x;
  zp[1] = x >> 8;
  zp[2] = x >> 16;
  zp[3] = x >> 24;
  return zp + 4;
#endif
}