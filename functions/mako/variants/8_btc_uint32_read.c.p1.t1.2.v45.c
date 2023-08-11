Here is a variant of the original function that maintains the original intention but changes the behavior by using loops to achieve byte-by-byte copying, instead of memcpy or bitwise operations directly:


btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn < 4)
    return 0;

#if defined(BTC_BIGENDIAN)
  *zp = 0;
  for (int i = 0; i < 4; ++i) {
    *zp = *zp | ((uint32_t)(*xp)[i] << (i * 8));
  }
#else
  uint8_t *zp_ptr = (uint8_t *) zp;
  for (size_t i = 0; i < sizeof(*zp); ++i) {
    zp_ptr[i] = (*xp)[i];
  }
#endif

  *xp += 4;
  *xn -= 4;

  return 1;
}


Note: It's important to make sure that the order of byte copying in the `elif` directive is consistent with the memory layout of `uint32_t` in your compiler and machine architecture. Depending on machine and complexity, bit shifts and bitwise OR may be more performant than byte-by-byte copying.
