btc_uint32_write(uint8_t *zp, uint32_t x) {
#ifndef BTC_BIGENDIAN
  *zp = x; zp++;
  *zp = x >> 8; zp++;
  *zp = x >> 16; zp++;
  *zp = x >> 24; zp++;
  return zp - 4;
#else
  uint32_t *int_pointer = (uint32_t *)zp;
  *int_pointer = x;
  return (uint8_t *)(int_pointer + 1);
#endif
}