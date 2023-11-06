btc_write32be(uint8_t *zp, uint32_t x) {
  uint32_t converted_x = htonl(x);
  #if defined(BTC_BIGENDIAN)
    memcpy(zp, &converted_x, sizeof(converted_x));
  #else
    zp[0] = (uint8_t)(converted_x >> 24);
    zp[1] = (uint8_t)(converted_x >> 16);
    zp[2] = (uint8_t)(converted_x >>  8);
    zp[3] = (uint8_t)(converted_x >>  0);
  #endif
}