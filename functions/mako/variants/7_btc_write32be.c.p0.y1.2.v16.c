
void btc_write32be(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  *zp = x;
#else
  zp[0] = x >> 24 & 0xFF;
  zp[1] = x >> 16 & 0xFF;
  zp[2] = x >> 8  & 0xFF;
  zp[3] = x & 0xFF;
#endif
}
