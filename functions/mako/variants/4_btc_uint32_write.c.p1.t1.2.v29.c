
void btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  zp[0] = (uint8_t) (x >>  0);
  zp[1] = (uint8_t) (x >>  8);
  zp[2] = (uint8_t) (x >> 16);
  zp[3] = (uint8_t) (x >> 24);
#else
  for(int i = 0; i < sizeof(x); ++i) {
    zp[i] = ((x >> (i * 8)) & 0xFF);
  }
#endif
}

This variant uses a loop in the little-endian case to write the bytes of `x` to `zp`, so it does not necessarily return a pointer. Also this function uses array indexing notation instead of incrementing the pointer.
The essential functionality of the code remains the same:
- On big endian systems, we write the bytes of `x` to `zp` in the same order.
- On little-endian systems, now we achieve the data copying by use of a loop logic, even without aid of `memcpy()`. And, it writes the data in the inverted order in your array to achieve the goal of writing the least significant byte first.
Additionally, function's prototype has changed due to it having "void" return type. </text>.</text> In the initial function, the pointer at which current operation had completed was returned, which is now not case with changed pointer return type to void, but still writing is done in the original manner and functionality maintained as required.