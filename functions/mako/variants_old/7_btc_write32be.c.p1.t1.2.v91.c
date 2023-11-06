btc_write32be(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  // switching to single byte assignment
  zp[0] = (x & 0xFF000000) >> 24;
  zp[1] = (x & 0x00FF0000) >> 16;
  zp[2] = (x & 0x0000FF00) >> 8;
  zp[3] = (x & 0x000000FF);
#else
  // swithcing to memcpy
  uint8_t temp[4];
  temp[0] = (x >> 24);
  temp[1] = (x >> 16);
  temp[2] = (x >> 8);
  temp[3] = (x >> 0);
  memcpy(zp, temp, sizeof(temp));
#endif
}