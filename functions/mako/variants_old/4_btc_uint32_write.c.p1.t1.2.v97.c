The function functionality as requested:


void btc_uint32_write(uint8_t *zp, uint32_t x) {
#ifdef BTC_BIGENDIAN
  x = __builtin_bswap32(x);
#endif
  memcpy(zp, &x, sizeof(x));
}
