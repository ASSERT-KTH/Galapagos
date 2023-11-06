Here is a variant using bitwise operators to achieve similar functionality.


btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn < 4)
    return 0;

  *zp = 0; // Initialize *zp to zero
#if defined(BTC_BIGENDIAN)
  for (int i = 0; i < 4; ++i) {
    *zp = (*zp << 8) + (*xp)[i];
  }
#else
  for (int i = 3; i >= 0; --i) {
    *zp = (*zp << 8) + (*xp)[i];
  }
#endif

  *xp += 4;
  *xn -= 4;

  return 1;
}

This version of the function accomplishes the same end goals with slightly restructured code. In the original, for a big-endian system, the bytes are shifted to the left by a specific value and then OR'ed together. In this variant, we carry this out in a loop, repeatedly shifting the value of *zp to the left and then adding the next byte. The functionality remains the same, but the implementation details are different. Similarly, for little-endian systems, the original use memcpy while this one reads the bytes directly in a little-endian manner.