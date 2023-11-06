Here is a variation of the original function maintaining its original functionality.


btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn < 4)
    return 0;

#if defined(BTC_BIGENDIAN)
  uint32_t tmp = 0;
  for(int i=0; i<4; i++) {
      tmp |= ((*xp)[i] << (i*8));
  }
  *zp = tmp;
#else
  *zp = ((*xp)[0]) | ((*xp)[1] <<  8) | ((*xp)[2] << 16) | ((*xp)[3] << 24);
#endif

  *xp += 4;
  *xn -= 4;

  return 1;
}

This version uses a for loop to read the bytes in BTC_BIGENDIAN systems. Here the possibility of undefined behavior with out-of-bounds access due to hardcoded indices is reduced. In the little-endian systems, the operation has been changed from memcpy to individual byte shifting operations, removing the library dependency of memcpy. Still note, the memory safety is not checked and can lead to unsafe behavior from calling this function in specific scenarios.