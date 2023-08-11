btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  return ((((uint32_t)xp[0]) <<  0)
       | (((uint32_t)xp[1]) <<  8)
       | (((uint32_t)xp[2]) << 16)
       | (((uint32_t)xp[3]) << 24)); 
#else
  uint32_t result;
  const unsigned char *p = xp;
  result = *p++;
  result |= (*p++ << 8);
  result |= (*p++ << 16);
  result |= (*p++ << 24);
  return result;
#endif
}