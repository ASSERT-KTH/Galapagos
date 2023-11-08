btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  uint32_t result = 0;
  result |= (uint32_t)xp[0] <<  0;
  result |= (uint32_t)xp[1] <<  8;
  result |= (uint32_t)xp[2] << 16;
  result |= (uint32_t)xp[3] << 24;
  return result;  
#else
  uint32_t z;
  for(size_t i = 0; i < sizeof(z); ++i) {
    z = z << 8 | xp[i];
  }
  return z;
#endif
}