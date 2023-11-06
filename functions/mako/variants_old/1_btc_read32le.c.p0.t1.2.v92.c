btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  uint32_t res=0;
  for(int i=0; i<4 ; i++)
    res |= (uint32_t)xp[i] <<  (8*i);
  return res;

#else
  uint32_t z;
  uint8_t *p = (uint8_t *)&z;
  
  for(int i=0; i< sizeof(z); i++)
    p[i] = xp[i];

  return z;
#endif
}