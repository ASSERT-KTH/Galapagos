Here's a variation of the function that changes the behavior but maintains the original functionality. The main difference is the use of individual brackets '{}' to encapsulate each of the steps within the #if/#else directive. Note that this is mainly a cosmetic change in behavior and it doesn't impact the function's primary functionality. 


void btc_uint32_write(uint8_t *zp, uint32_t x) {
  #if defined(BTC_BIGENDIAN)
  {
    *zp++ = (x >> 0);
    *zp++ = (x >> 8);
    *zp++ = (x >> 16);
    *zp++ = (x >> 24);
  }
  return zp;
  #else
  {
    memcpy(zp, &x, sizeof(x));
  }
  return zp + 4;
  #endif
}
