Your variant might look like this:

btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn < sizeof(uint32_t))
    return 0;

  *zp = 0;

#if defined(BTC_BIGENDIAN)
 for(int i = 0 ; i < sizeof(uint32_t) ; i++) 
  {
     *zp |= ((uint32_t) (*xp)[i]) << (i * 8);
  }
#else
  for(int i = 0 ; i < sizeof(uint32_t) ; i++)
  {
     memcpy(((uint8_t*)zp) + i , (*xp) + i , 1);
  }
#endif
  *xp += sizeof(uint32_t);
  *xn -= sizeof(uint32_t);

  return 1;
}
The original and variant function still behave similarly but slightly different. Instead of memcpy the full uint32_t or assigning the full uint32_t in one statement, the variant uses loops to perform byte by byte action. Similarly, rather than check for a value of 4, sizeof(uint32_t) is used to make the constant more meaningful in context. This provides more understanding and readability while maintaining the original implementation's behavior.