Here is a program variant that includes a cast to a pointer to a uint32_t. This should be pointed out, however, that this will only work reliably on platforms that do not require strict alignment or do not have issues with unaligned reads.


uint32_t btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  return ((uint32_t)xp[0] <<  0)
       | ((uint32_t)xp[1] <<  8)
       | ((uint32_t)xp[2] << 16)
       | ((uint32_t)xp[3] << 24);
#else
  return *(uint32_t *)xp;
#endif
}

Please be aware that, while bypassing memcpy using pointer casting like in the example above might be faster, misuse of it can lead to incorrect results or indeed even to crashing applications - different architectures have different requirements and restrictions related to alignment.

The earlier version with memcpy for the little-endian case should work better across different architectures (particularly ones that don't allow unaligned reads or writes). It's possible the compiler will optimize the memcpy into the equivalent faster operation on platforms where it's safe to do so anyway. It's often preferred to let the compiler make these decisions where it can, rather than second-guessing it unnecessarily. 

This pointer casting version might perform faster on certain architectures, but I would expect that difference to be negligible in most realistic-use scenarios. If you're concerned about micro-optimizations like this and need to ensure maximal performance across a range of architectures, you should conduct your benchmarks to identify the most effective approach.