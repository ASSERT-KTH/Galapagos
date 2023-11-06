btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  uint8_t *tmp = zp;
  tmp[0] = (x >> 24);
  tmp[1] = (x >> 16);
  tmp[2] = (x >> 8);
  tmp[3] = (x >> 0);
  return zp + 4;
#else
  ZP[0] = x & 0xFF;
  ZP[1] = (x>>8) & 0xFF;
  ZP[2] = (x>>16) & 0xFF;
  ZP[3] = (x>>24) & 0xFF;
  return zp + 4;
#endif
}