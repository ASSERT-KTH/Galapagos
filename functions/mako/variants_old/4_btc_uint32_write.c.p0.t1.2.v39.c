btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  *zp++ = (uint8_t)(x & 0xFF);
  *zp++ = (uint8_t)((x >> 8) & 0xFF);
  *zp++ = (uint8_t)((x >> 16) & 0xFF);
  *zp++ = (uint8_t)((x >> 24) & 0xFF);
  return zp;
#else
  uint8_t *temp = (uint8_t *)&x;
  *zp++ = *temp++;
  *zp++ = *temp++;
  *zp++ = *temp++;
  *zp++ = *temp++;
  return zp;
#endif
}