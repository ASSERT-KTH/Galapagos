btc_write32be(uint8_t *zp, uint32_t x) {
  uint8_t byteArray[4];

#if defined(BTC_BIGENDIAN)
  memcpy(byteArray, &x, sizeof(x));
  memcpy(zp, byteArray, sizeof(byteArray));
#else
  byteArray[0] = (uint8_t)(x >> 24);
  byteArray[1] = (uint8_t)(x >> 16);
  byteArray[2] = (uint8_t)(x >>  8);
  byteArray[3] = (uint8_t)(x >>  0);
  memcpy(zp, byteArray, sizeof(byteArray));
#endif
}