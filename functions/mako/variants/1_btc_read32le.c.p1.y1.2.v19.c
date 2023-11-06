btc_read32le_1(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
    uint32_t res = xp[0];
    res |= xp[1] << 8;
    res |= xp[2] << 16;
    res |= xp[3] << 24;
    return res;
#else
    uint32_t res;
    unsigned i;
    for (i = 0; i < sizeof(res); i++) {
        memcpy((((uint8_t*)&res)+i), (xp+i), 1);
    }
    return res;
#endif
}

btc_read32le_2(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  return (((uint32_t)xp[0])
       | ((uint32_t)xp[1] << 8)
       | ((uint32_t)xp[2] << 16)
       | ((uint32_t)xp[3] << 24));
#else
  uint32_t res;
  unsigned char* temp = (unsigned char*) &res;
  temp[0] = xp[0];
  temp[1] = xp[1];   
  temp[2] = xp[2]; 
  temp[3] = xp[3]; 
  return res;
#endif
}

btc_read32le_3(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
    uint32_t ret_val = *xp++;
    ret_val |= ((uint32_t)*xp++) << 8;
    ret_val |= ((uint32_t)*xp++) << 16;
    ret_val |= ((uint32_t)*xp++) << 24;
    return ret_val;
#else
  uint32_t z;
  for(int i=0; i<sizeof(z); i++)
    ((char*)&z)[i] = xp[i];
  return z;
#endif
}