btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  *zp++ = x & 0xff;
  x >>= 8;
  *zp++ = x & 0xff;
  x >>= 8;
  *zp++ = x & 0xff;
  x >>= 8;
  *zp++ = x & 0xff;
  return zp;
#else
  uint32_t *int_ptr = (uint32_t *)zp;
  *int_ptr = x;
  return zp + 4;
#endif
}