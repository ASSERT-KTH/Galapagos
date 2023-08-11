btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  uint32_t ret = 0;
  for(int i = 0; i < 4; i++) {
    ret |= (uint32_t)xp[i] << (i*8);
  }
  return ret;
#else
  uint32_t z = 0;
  uint8_t * ptr = (uint8_t *) &z;
  for(size_t i=0; i < sizeof(z); i++){
    ptr[i] = xp[i];
  }
  return z;
#endif
}