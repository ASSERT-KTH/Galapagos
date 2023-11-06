The given function writes a 32 bit number to the location pointed by 'zp'. The written sequence starts with the least-significant byte. If the 'BTC_BIGENDIAN' macro is defined, the bytes are manually written in big-endian order otherwise, the memory copy function is used which adheres to platform's endianness. Now, the function can be rewritten as:


void btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  zp[0] = (x >>  0) & 0xff;
  zp[1] = (x >>  8) & 0xff;
  zp[2] = (x >> 16) & 0xff;
  zp[3] = (x >> 24) & 0xff;
#else
  uint32_t *p = (uint32_t*)zp;
  *p = x;
#endif
}

In the revised code, I've used direct array assignment instead of pointer incrementing. It helps in better understanding the byte ordering as compared to 'zp++' operations in the previous code.
In little-endian variant, instead of copying all bytes using 'memcpy', I directly copied the 'uint32_t' number using typecasting. It eliminates the need of 'sizeof' function there. The original behavior like the function signature, endianness adherence, etc. are all maintained. Although arrays have been used instead of pointer increment, it's only for code readability and both are functionally similar with regards to memory.