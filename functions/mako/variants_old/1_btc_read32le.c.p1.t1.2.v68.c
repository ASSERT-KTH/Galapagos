Here is a variation of the function, changing the behavior of the function under the non-big-endian branch to manually piece together the 32-bit integer instead of using memcmp function:


btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  return ((uint32_t)xp[0] <<  0)
       | ((uint32_t)xp[1] <<  8)
       | ((uint32_t)xp[2] << 16)
       | ((uint32_t)xp[3] << 24);
#else
  uint32_t z = 0;
  for(int i=0; i<4; i++){
    z |=((uint32_t)xp[i])<<(8*i);
  }
  return z;
#endif
}

This alternative way eliminates the dependency on the memcpy function, which might potentially accelerate execution. Detailed performance behaviors would still depend a lot on various factors, including the specific hardware architecture, your compiler’s various aggressiveness in optimizations (eg. loop unrolling and function inlining), cache behavior, etc. Always use profiling tools in such uncertainty to avoid premature optimization. Please notice relevant testing be performed before making the decision whether to replace the library function.