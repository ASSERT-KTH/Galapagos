Here is a variant function which maintains the original functionality while changing the behavior. In this variant for little endian, the value of `x` is manually written byte-by-byte into `zp` rather than using `memcpy()`. This matches what is done in the big endian case.


void btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  *zp++ = (uint8_t)(x >>  0);
  *zp++ = (uint8_t)(x >>  8);
  *zp++ = (uint8_t)(x >> 16);
  *zp++ = (uint8_t)(x >> 24);
#else
  *zp++ = (uint8_t)(x >>  0);
  *zp++ = (uint8_t)(x >>  8);
  *zp++ = (uint8_t)(x >> 16);
  *zp++ = (uint8_t)(x >> 24);
#endif
}


Note however, this removed the need for the `BTC_BIGENDIAN` ifdef. It could simply be written as:


void btc_uint32_write(uint8_t *zp, uint32_t x) {
  *zp++ = (uint8_t)(x >>  0);
  *zp++ = (uint8_t)(x >>  8);
  *zp++ = (uint8_t)(x >> 16);
  *zp++ = (uint8_t)(x >> 24);
}


This version also avoids invoking undefined behavior caused by using `memcpy()` to alias `uint32_t` as `uint8_t`. Since these two types don't share compatible (or identical) types, violating the strict-aliasing rule may lead to an unexepected result on certain platforms / compilers with `-O2` or above optimization level.