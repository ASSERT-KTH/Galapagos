Here's a minor modification to the original function code. This modified code maintains the original functionality of the function, but changes its approach slightly.


void btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  zp[0] = (x >>  0) & 0xFF;
  zp[1] = (x >>  8) & 0xFF;
  zp[2] = (x >> 16) & 0xFF;
  zp[3] = (x >> 24) & 0xFF;
#else
  zp[0] = x & 0xFF;
  zp[1] = (x >> 8) & 0xFF;
  zp[2] = (x >> 16) & 0xFF;
  zp[3] = (x >> 24) & 0xFF;
#endif
  return;
}

In the big-endian implementation the logical "and" operation with `0xFF` ensures only the last significant byte will be copied. To maintain the function's signature, it's had to be changed to `void` in the prototype and the return at the end of the function.