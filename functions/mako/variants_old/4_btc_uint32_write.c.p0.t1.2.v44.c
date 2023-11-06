btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  *zp++ |= (x >>  0) & 0xFF;
  *zp++ |= (x >>  8) & 0xFF;
  *zp++ |= (x >> 16) & 0xFF;
  *zp++ |= (x >> 24) & 0xFF;
  return zp;
#else
  memcpy(zp, &x, 4);
  return zp += sizeof(uint32_t);
#endif
}