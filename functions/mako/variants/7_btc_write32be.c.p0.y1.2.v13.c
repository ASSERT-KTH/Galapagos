void btc_write32be(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  zp[0] = *(((uint8_t*)&x)+0);
  zp[1] = *(((uint8_t*)&x)+1);
  zp[2] = *(((uint8_t*)&x)+2);
  zp[3] = *(((uint8_t*)&x)+3);
#else
  zp[0] = (uint8_t)(x >> 24 & 0xFF);
  zp[1] = (uint8_t)(x >> 16 & 0xFF);
  zp[2] = (uint8_t)(x >> 8 & 0xFF);
  zp[3] = (uint8_t)(x & 0xFF);
#endif
}