Here is a variant that changes the behavior of the original function but maintains the same functionality. The changes are mostly stylistic -- converting the post-increment usage in pointers to normal increment use, using explicit sizeof(uint32_t) to denote the size and replacing #if defined(BTC_BIGENDIAN) check with if (__BYTE_ORDER__ == __ORDER_BIG_ENDIAN__) and vice-versa.

btc_uint32_write(uint8_t *zp, uint32_t x) {
#ifdef __GNUC__
  if (__BYTE_ORDER__ == __ORDER_BIG_ENDIAN__)
#else
  if(is_bigendian())
#endif
  {
    zp[0] = (x >>  0);
    zp[1] = (x >>  8);
    zp[2] = (x >> 16);
    zp[3] = (x >> 24);
    zp+=4;
  }
  else
  {
    memcpy(zp, &x, sizeof(uint32_t));
    zp += sizeof(uint32_t);
  }
  return zp;
}