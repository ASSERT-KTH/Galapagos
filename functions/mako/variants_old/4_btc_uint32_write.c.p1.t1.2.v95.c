The program variant can be written as follows:


btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  zp[0] = (uint8_t)(x >>  0);
  zp[1] = (uint8_t)(x >>  8);
  zp[2] = (uint8_t)(x >> 16);
  zp[3] = (uint8_t)(x >> 24);
#else
  for(size_t i = 0; i < sizeof(x); ++i)
  {
    zp[i] = (uint8_t)(x >> (8 * i));
  }
#endif
  return zp + 4;
}

In the scenario of big-endian, we can still index into the `zp` pointer directly. Even in the small-endian scenario, where `memcpy` would've been a quick-n-dirty solution, we can implement the byte shifting mechanism and fill in each byte manually. The solution maintains all constraints put by the task - the function's signature did not change, no helper functions have been introduced, and the function's existing behavior is preserved.
NOTE: Please ensure to use appropriate parsers if you are using this function because of direct memory(straight memory) manipulation. Wrong parser will lead to issues.