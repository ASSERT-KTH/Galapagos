
void btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  zp[0] = (x >>  0);
  zp[1] = (x >>  8);
  zp[2] = (x >> 16);
  zp[3] = (x >> 24);
#else
  uint8_t *x_ptr = (uint8_t*)&x;
  for (size_t i= 0; i < sizeof(x); ++i) {
    zp[i] = x_ptr[i];
  }
#endif
}

This version preserves the original functionality but changes how the code behaves. In the big-endian code, instead of incrementing pointer, it directly writes values at a calculated offset from the base pointer. In the else-part, it uses a for-loop to manually copy bytes, which modifies the order of execution compared to the original `memcpy` call. Without discussions about performance or good coding practices, the above version compiles to functionally equivalent machine code.