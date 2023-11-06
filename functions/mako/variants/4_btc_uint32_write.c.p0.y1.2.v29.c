
void btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  zp[0] = x & 0xff;
  zp[1] = (x >> 8) & 0xff;
  zp[2] = (x >> 16) & 0xff;
  zp[3] = (x >> 24) & 0xff;
#else
  uint32_t *dest = (uint32_t *)zp;
  *dest = x;
  zp += sizeof(uint32_t);
#endif
}
