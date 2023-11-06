uint32_t btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  uint32_t outcome = 0;
  for(int i = 0; i < 4; i++) {
    outcome |= ((uint32_t)xp[i] << (i * 8));
  }
  return outcome;
#else
  uint32_t z = 0;
  for(int i = 0; i < sizeof(z); i++) {
    ((uint8_t*)&z)[i] = xp[i];
  }
  return z;
#endif
}