Here is a variant of the function that uses bitwise operator and a loop, which still provides the same functionality but changes the implementation details:


void btc_write32be(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  memcpy(zp, &x, sizeof(x));
#else
  int i;
  for (i = 0; i < sizeof(uint32_t); i++) {
    zp[i] = (x >> ((3 - i) * 8));
  }
#endif
}


In this version, the operation (x >> ((3 - i) * 8)) does the same as the shifted values in the original code, whereas the loop condition reduces the hardcoded indexing addressing to a looping variable 'i'. Any changes in the prep processor directives or stricter error checking/logic were avoided to give almost same behaviour as original.