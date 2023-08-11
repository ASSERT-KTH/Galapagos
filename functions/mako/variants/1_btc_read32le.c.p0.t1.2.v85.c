btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  uint8_t values[4];

  for (int i = 0; i < 4; ++i) {
    values[i] = xp[i];
  }

  return ((uint32_t)values[0] <<  0)
       | ((uint32_t)values[1] <<  8)
       | ((uint32_t)values[2] << 16)
       | ((uint32_t)values[3] << 24);
#else
  uint32_t z;
  for (size_t i = 0; i < sizeof(z); ++i){
    ((uint8_t *)&z)[i] = xp[i];
  }
  return z;
#endif
}