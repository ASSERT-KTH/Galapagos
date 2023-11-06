btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  uint32_t bytes_after_shifting[4];
  for(int i = 0; i < 4; i++)
       bytes_after_shifting[i] = ((uint32_t)xp[i]) << (8*i);
  
  return bytes_after_shifting[0]
       | bytes_after_shifting[1]
       | bytes_after_shifting[2]
       | bytes_after_shifting[3];
#else
  uint32_t z;
  for(int i = 0; i < sizeof(z); i++)
       ((uint8_t*) &z)[i] = xp[i];
  return z;
#endif
}