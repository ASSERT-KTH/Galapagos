btc_write32be(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  x = ((x << 24) & 0xFF000000U) | ((x << 8) & 0x00FF0000U) | ((x >> 8) & 0x0000FF00U) | ((x >> 24) & 0x000000FFU);
  memcpy(zp, &x, sizeof(x));
#else
  zp[0] = (x & 0xFF000000) >> 24;
  zp[1] = (x & 0x00FF0000) >> 16;
  zp[2] = (x & 0x0000FF00) >> 8;
  zp[3] = (x & 0x000000FF);
#endif
}