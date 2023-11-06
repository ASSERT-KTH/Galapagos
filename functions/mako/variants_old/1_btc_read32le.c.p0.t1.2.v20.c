btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  return ((uint32_t)((xp[0] << 0) & 0xFF)) 
       | ((uint32_t)((xp[1] << 8) & 0xFF00)) 
       | ((uint32_t)((xp[2] << 16) & 0xFF0000)) 
       | ((uint32_t)((xp[3] << 24) & 0xFF000000));
#else
  uint32_t z;
  nptr = (const char*)xp;
  sscanf(nptr,"%u",&z);
  return z;
#endif
}