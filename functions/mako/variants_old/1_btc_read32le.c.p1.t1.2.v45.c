
btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  uint32_t z = 0;
  for(int i = 0; i < 4; i++) {
    z |= ((uint32_t)xp[i] << (i * 8));
  }
  return z;
#else
  uint32_t z = 0;
  for(int i = sizeof(z)-1; i >= 0; i--) {
    z = (z << 8) | xp[i];
  }
  return z;
#endif
}
