1. Reading bytes one at a time in BE/LE machine


uint32_t btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  return ((uint32_t)xp[0]) 
       | ((uint32_t)xp[1] <<  8) 
       | ((uint32_t)xp[2] << 16) 
       | ((uint32_t)xp[3] << 24);
#else
  return ((uint32_t)xp[0]) 
       | ((uint32_t)xp[1] <<  8) 
       | ((uint32_t)xp[2] << 16) 
       | ((uint32_t)xp[3] << 24);
#endif
} 


2. Looping through bytes

uint32_t btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  uint32_t res = 0;
  for (int i = 0; i < 4; i++){
    res |= ((uint32_t)xp[i] << (8*i));
  }
  return res;
#else
  uint32_t z;
  memcpy(&z, xp, sizeof(z));
  return z;
#endif
}


3. Using Typecasting


uint32_t btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  uint32_t res = ((uint32_t*)xp)[0];
  return ( ((res & 0x000000FF) << 24)
         | ((res & 0x0000FF00) <<  8)
         | ((res & 0x00FF0000) >>  8) 
         | ((res & 0xFF000000) >> 24) );
#else
  return ((uint32_t*)xp)[0];
#endif
} 


4. Rewriting the memory copying operation using a char pointer


uint32_t btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  return ((uint32_t)xp[0] <<  0)
       | ((uint32_t)xp[1] <<  8)
       | ((uint32_t)xp[2] << 16)
       | ((uint32_t)xp[3] << 24);
#else
  uint32_t z;
  char *pTmp = (char *)&z;
  for (int i = 0; i < sizeof(z); i++)
  {
    pTmp[i] = xp[i];
  }
  return z;
#endif
}
