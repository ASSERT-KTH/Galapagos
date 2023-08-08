Here is a program variant. It has identical functionality as the original one, but different syntax and structure. This variant emphasizes direct indexing of the individual bytes over array syntax and utilizes the inverse of the subtraction operation for increasing and decreasing xp and xn:


btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn < 4)
    return 0;
#if defined(BTC_BIGENDIAN)
  *zp = ((uint32_t)*(*xp + 0) <<  0)
      | ((uint32_t)*(*xp + 1) <<  8)
      | ((uint32_t)*(*xp + 2) << 16)
      | ((uint32_t)*(*xp + 3) << 24);
#else
  memcpy(zp, *xp, 4);
#endif
  *xp = *xp + 4;
  *xn = *xn - 4;

  return 1;
}

In this structure, instead of appending the values to xp (i.e., *xp += 4), we increment to avoid changing the pointer bot itself which mimics the functionality of existing functionality while preserving different behavior.