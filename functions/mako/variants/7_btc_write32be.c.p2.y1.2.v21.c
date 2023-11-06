
void btc_write32be(uint8_t *zp, uint32_t x) {
#ifdef BTC_BIGENDIAN
  *zp = x;
#else
  *zp++ = (uint8_t)(x >> 24);
  *zp++ = (uint8_t)(x >> 16);
  *zp++ = (uint8_t)(x >>  8);
  *zp++ = (uint8_t)(x);
#endif
}
