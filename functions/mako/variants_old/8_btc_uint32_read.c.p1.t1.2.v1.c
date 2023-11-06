Here's a program variant that achieves the same functionality:


btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn < sizeof(*zp))
    return 0;

#if defined(BTC_BIGENDIAN)
  *zp = (*xp)[0] | ((*xp)[1] << 8) | ((*xp)[2] << 16) | ((*xp)[3] << 24);
#else
  *zp = (**xp) | ((*(*xp+1)) << 8) | ((*(*xp+2)) << 16) | ((*(*xp+3)) << 24);
#endif

  *xp += sizeof(*zp);
  *xn -= sizeof(*zp);

  return 1;
}


This variant changes bitwise shift operation and comparison with sizeof operator for reduced endian ambiguity. For the non-big-endian case, it directly dereferences each byte of `*zp` instead of using `memcpy`. This variant manually carries out the same operation in both big- and non-big-endian cases such that it moderately improves the readability since initial one was evidently concise for the sake of efficiency. Note that functionality stays the same. But again, all optimization considerations being neglected herein, specific micro-benchmarking would determine whether this version performs worse or better.