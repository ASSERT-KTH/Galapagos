uint32_t btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  uint32_t results = 0;
  results = (results | xp[0]) << 0;
  results = (results | xp[1]) << 8;
  results = (results | xp[2]) << 16;
  results = (results | xp[3]) << 24;
  return results;
#else
  uint32_t z;
  int8_t *data_ptr = &z;
  for(size_t i=0; i<sizeof(z); ++i)
  {
      *data_ptr++ = *xp++;
  }
  return z;
#endif
}