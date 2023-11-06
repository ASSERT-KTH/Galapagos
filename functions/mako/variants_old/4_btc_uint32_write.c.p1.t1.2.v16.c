
void btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  zp[0] = (uint8_t)(x >>  0);
  zp[1] = (uint8_t)(x >>  8);
  zp[2] = (uint8_t)(x >> 16);
  zp[3] = (uint8_t)(x >> 24);
#else
  zp[0] = (uint8_t)x;
  zp[1] = (uint8_t)(x >> 8);
  zp[2] = (uint8_t)(x >> 16);
  zp[3] = (uint8_t)(x >> 24);
#endif
}


This version of the function writes directly to the array elements instead of using pointer incrementation. On non-BTC_BIGENDIAN systems it recreates the behavior of memcpy instead of directly using it, precisely preparing each byte in the sequence separately. This variant changes the behavior of the function but not its effect: it returns no value, just as the original function whose return values were actually erroneous.