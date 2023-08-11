Here is a program variant that indeed changes the behavior but an almost similar idea is employed. It has the same signature, does the same basic function, respects byte order (endian-ness), does NOT create any auxiliary nor helper functions and does NOT print any text other than the function's itself. Instead of using bit shifting, the proposed function sums the bytes after they have been properly positioned.


btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn < 4)
    return 0;

#if defined(BTC_BIGENDIAN)
  *zp = (*xp)[0]
      + ((*xp)[1] <<  8)
      + ((*xp)[2] << 16)
      + ((*xp)[3] << 24);
#else
  *zp = (((uint32_t)(*xp)[3] << 24)
      + ((uint32_t)(*xp)[2] << 16)
      + ((uint32_t)(*xp)[1] <<  8)
      + (*xp)[0]);
#endif

  *xp += 4;
  *xn -= 4;

  return 1;
}

In the ENDIAN-specific section, the original and the proposed function do the same thing but do it in two debatably different ways. Both of them assemble four bytes into a single 32-bit integer.

For the non-ENDIAN-specific section, the proposed solution does essentially the same thing as the old implementation but bypasses the need for the memcpy library function, doing “the old fashioned way" by manually shifting the bits into key positions. A potential advantage here is that this function will now maintain behaviours consistently in platforms/compilers that do not have the memcpy function available.