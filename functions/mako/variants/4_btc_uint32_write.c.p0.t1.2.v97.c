btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  *zp++ = (x & 0xFF);
  x >>= 8;
  *zp++ = (x & 0xFF);
  x >>= 8;
  *zp++ = (x & 0xFF);
  x >>= 8;
  *zp = (x & 0xFF);
  return zp + 1;
#else
  *((uint32_t *)zp) = x;
  return zp + sizeof(uint32_t);
#endif
}