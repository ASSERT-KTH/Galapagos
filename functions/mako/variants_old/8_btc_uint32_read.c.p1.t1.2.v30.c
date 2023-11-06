
btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn < sizeof(uint32_t))
    return 0;

#if defined(BTC_BIGENDIAN)
  *zp = 0;
  for (int i=0; i<4; i++)
    *zp |= ((uint32_t)(*xp)[i] << (i*8));
#else
  *zp = *((uint32_t*)(*xp));
#endif

  *xp += sizeof(uint32_t);
  *xn -= sizeof(uint32_t);

  return 1;
}

Essentially the function functionality hasn't really changed, but the implementation is slightly different. Example shown, in the big-endian setup, used a for loop control structure to accomplish the bitwise shifting. For the non-big-endian condition, instead of using `memcpy()` the code dereferenced the `*xp` value and copied with an assignment operator. Both versions maintain the functionality of the original implementation.