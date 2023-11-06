btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  uint32_t ret_val = 0;
  for (int i = 0; i <=3; i++)
    ret_val |= (uint32_t)xp[i] << (i*8);
  return ret_val;
#else
  uint32_t z;
  unsigned int length = sizeof(z);
  for(int i=0; i<length; i++){
     ((uint8_t*)&z)[i] = xp[i];
  }
  return z;
#endif
}