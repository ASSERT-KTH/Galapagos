
void btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  *zp++ = (x >> 24) & 0xff;
  *zp++ = (x >> 16) & 0xff;
  *zp++ = (x >> 8) & 0xff;
  *zp++ = x & 0xff;
#else
  *zp++ = x & 0xff;
  *zp++ = (x >> 8) & 0xff;
  *zp++ = (x >> 16) & 0xff;
  *zp++ = (x >> 24) & 0xff;
#endif
}

This changes the behavior of the original function by directly storing the shifted x's bytes in the uint8_t array instead of copying the memory. But it maintains original functionality as whether it's BTC_BIGENDIAN or little endian, the code writes in the correct bytes order. It also maintains function's signature, and doesn't generate more helper or auxiliary functions.