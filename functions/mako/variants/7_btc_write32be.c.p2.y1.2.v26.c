void btc_write32be(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  int y = 0;
  uint8_t temp[sizeof(int)];
  for (y=0; y<sizeof(x); y++){
      temp[y] = ((x >> (sizeof(int) - y - 1) * 8) & 0xFF);
  }
  memcpy(zp, &temp, sizeof(int));
#else
  zp[3] = (uint8_t)(x & 0xFF);
  zp[2] = (uint8_t)((x >> 8) & 0xFF);
  zp[1] = (uint8_t)((x >> 16) & 0xFF);
  zp[0] = (uint8_t)((x >> 24) & 0xFF);
#endif
}