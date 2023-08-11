btc_write32be(uint8_t *zp, uint32_t y) {
#if defined(BTC_BIGENDIAN)
  memcpy(zp, &y, sizeof(y));
#else
  zp[0] = (uint8_t)(y >> 24) & 0xFF;
  zp[1] = (uint8_t)(y >> 16) & 0xFF;
  zp[2] = (uint8_t)(y >> 8)  & 0xFF;
  zp[3] = (uint8_t)y & 0xFF;
#endif
}