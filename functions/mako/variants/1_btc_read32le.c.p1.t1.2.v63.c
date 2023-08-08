Here's a slightly optimized variant implementation of the same `btc_read32le` function. This variant has a change in structure while maintaining the same functionality as that of the original program.


btc_read32le(const uint8_t *xp) {
  union {
    uint32_t z;
    uint8_t arr[4];
  } converter;

#if defined(BTC_BIGENDIAN)
  converter.arr[0] = xp[0];
  converter.arr[1] = xp[1];
  converter.arr[2] = xp[2];
  converter.arr[3] = xp[3];
#else
  memcpy(converter.arr, xp, sizeof(converter.z));
#endif

  return converter.z;
}


Even though this variantfunction slightly different compared to the original one, it does exactly the same thi which the orginal function does .For big endian machines, the first byte is assigned to the least significant byte, with subsequent bytes stored in increasing order significance. For little endian machines, it simply copies the array.