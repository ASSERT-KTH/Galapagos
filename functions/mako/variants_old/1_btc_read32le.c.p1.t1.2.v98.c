btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  uint32_t z = 0;
  z |= ((uint32_t)xp[0] <<  0);
  z |= ((uint32_t)xp[1] <<  8);
  z |= ((uint32_t)xp[2] << 16);
  z |= ((uint32_t)xp[3] << 24);
  return z;
#else
  uint32_t z = 0;
  for (int i = 0; i < sizeof(z); i++) {
      z |= ((uint32_t)xp[i] << (i * 8));
  }
  return z;
#endif
}