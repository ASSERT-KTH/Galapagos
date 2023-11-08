btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  uint32_t output = 0;
  for(int i = 0; i < 4; i++) {
    output |= ((uint32_t)xp[i] << (i*8));
  }
  return output;
#else
  uint32_t z;
  for(int i = 0; i < sizeof(z); i++) {
    ((uint8_t *)&z)[i] = xp[i];
  }
  return z;
#endif
}