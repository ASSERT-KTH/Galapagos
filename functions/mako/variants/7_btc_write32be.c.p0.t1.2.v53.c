btc_write32be(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  if(zp != NULL) {
    memcpy(zp, &x, sizeof(x));
  } else {
    return;
  }
#else
  if(zp != NULL) {
    zp[0] = (uint8_t)(x >> 24) & 0xFF;
    zp[1] = (uint8_t)(x >> 16) & 0xFF;
    zp[2] = (uint8_t)(x >> 8) & 0xFF;
    zp[3] = (uint8_t)(x)      & 0xFF;
  } else {
    return;
  }
#endif
}