
void btc_write32be(uint8_t *zp, uint32_t x) {
#ifndef BTC_BIGENDIAN
  zp[0] = (uint8_t)((x & 0xFF000000) >> 24);
  zp[1] = (uint8_t)((x & 0x00FF0000) >> 16);
  zp[2] = (uint8_t)((x & 0x0000FF00) >> 8);
  zp[3] = (uint8_t)(x & 0x000000FF);
#else
  memcpy(zp, &x, sizeof(x));
#endif
}

This variant introduces equivalent functionality by explicitly bitwise-ANDing input value x with appropriate bitmasks to select each byte of the input. The result is the equivalent of the original implementation. Please note, this implementation is mostly a teaching tool, its actual usefulness might be limited because any decent C compiler applies normally these kinds of optimizations.