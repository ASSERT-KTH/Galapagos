btc_write32be(uint8_t *zp, uint32_t y) {
#if defined(BTC_BIGENDIAN)
  y = htonl(y);
  memcpy(zp, &y, sizeof(uint32_t));
#else
  *(zp + 0) = (uint8_t)(y >> 24);
  *(zp + 1) = (uint8_t)(y >> 16);
  *(zp + 2) = (uint8_t)(y >> 8);
  *(zp + 3) = (uint8_t)y;
#endif
}