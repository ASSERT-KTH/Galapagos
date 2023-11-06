btc_write32be(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  uint32_t temp = htonl(x);
  memcpy(zp, &temp, sizeof(temp));
#else
  zp[0] = (uint8_t)((x & 0xFF000000) >> 24);
  zp[1] = (uint8_t)((x & 0x00FF0000) >> 16);
  zp[2] = (uint8_t)((x & 0x0000FF00) >> 8);
  zp[3] = (uint8_t)(x & 0x000000FF);
#endif
}