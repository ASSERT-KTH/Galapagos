Here's a variation of the function that makes use of loop and bitwise shift and OR operations. It maintains the behavior and original functionality of the function:


void btc_write32be(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  memcpy(zp, &x, sizeof(x));
#else
  for (int i = 0; i < 4; ++i) {
    zp[i] = x >> ((3 - i) * 8) & 0xFF;
  }
#endif
}


In the #else branch, instead of manually listing all four iterations, we've added a for loop that runs four (4) times. The operation `x >> ((3 - i) * 8)` in each iteration will shift the integer `x` the appropriate amount to get each byte from most significant to least, which are then written into `zp`. This will store the bytes in big endian format just like in the original code.