Here is the program variant: 


btc_write32be(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  uint8_t *xp = (uint8_t *)&x;
  for (int i = 0; i < sizeof(x); i++) {
    zp[i] = xp[i];
  }
#else
  for (int i = 0; i < sizeof(x); i++) {
    zp[i] = (x >> ((3 - i) * 8)) & 0xff;
  }
#endif
}


This variant produces the same end result as the original function, but it uses a loop to iterate through the bytes of `x`, allowing much easier expansion to process larger or smaller operand sizes. The big-endian variant remains essentially the same, using a pointer to iterate through the source data byte by byte to preserve its original big-endian byte order.

In the little-endian variant, the index `i` iterates from the most significant byte to the least significant. The expression `(3 - i) * 8` computes a rotation count that positions each successive 8-bit group to the least significant position where its bits will populate the low-order byte of a `uint8_t` quantity when it is copied to `zp[i]`. The bitwise AND operation `& 0xff` clears all but the low-order 8 bits from this value before it is stored in `zp[i]`.