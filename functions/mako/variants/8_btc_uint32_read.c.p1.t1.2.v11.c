
btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn < sizeof(uint32_t))
    return 0;

#if defined(BTC_BIGENDIAN)
  *zp = ((*xp)[0] <<  0)
      | ((*xp)[1] <<  8)
      | ((*xp)[2] << 16)
      | ((*xp)[3] << 24);
#else
  *zp = (**xp & *((const uint32_t *) *xp));
#endif

  *xp += sizeof(uint32_t);
  *xn -= sizeof(uint32_t);

  return 1;
}

In this variant, the same functionality is maintained with slight changes as follows:

- Changed hardcoded "4" to sizeof(uint32_t) - to ensure portability across platforms where the size of uint32_t may not be 4 bytes
- Used '&' operator in the non big-endian ifdef to logically '&' directly with the input, which effectively does a memcpy operation
