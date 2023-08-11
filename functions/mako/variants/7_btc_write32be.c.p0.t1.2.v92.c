btc_write32be(uint8_t *zp, uint32_t y) {
#if defined(BTC_BIGENDIAN)
  memcpy(zp, &y, sizeof(y));
#else
  zp[3] = y & 0x000000FF;
  zp[2] = (y & 0x0000FF00) >>  8;
  zp[1] = (y & 0x00FF0000) >> 16;
  zp[0] = (y & 0xFF000000) >> 24;
#endif
}