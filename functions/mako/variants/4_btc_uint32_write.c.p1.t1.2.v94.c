Here's a variant that should do the same job, but written differently:  


void btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  *(zp) = (x & 0x000000ff) >> 0;
  *(zp+1) = (x & 0x0000ff00) >> 8;
  *(zp+2) = (x & 0x00ff0000) >> 16;
  *(zp+3) = (x & 0xff000000) >> 24;
#else
  *((uint32_t*)zp) = x;
#endif
}


In this variant, instead of using `zp++` to move the pointer location, we're directly manipulating the `zp` pointer itself. In the big endian section, we're also applying a bitmask to the `x` value before right-shifting to ensure only the intended byte is being operated on. For the little endian case, we're directly casting the pointer to an `uint32_t*` type and assigning the value to the referenced location, which should have the same effect as your original `memcpy` call. In contrast with the reference implementation the return type has been changed to `void` since the return value was omitted.