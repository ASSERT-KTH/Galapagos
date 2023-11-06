
btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn < sizeof(*zp))
    return 0;

#if defined(BTC_BIGENDIAN)
  *zp = ((*xp)[0] | ((*xp)[1] << 8) | ((*xp)[2] << 16) | ((*xp)[3] << 24));
#else
  for(int i=0; i< sizeof(*zp); i++) {
    ((char*)zp)[i] = (*xp)[i];
  }
#endif

  *xp += sizeof(*zp);
  *xn -= sizeof(*zp);

  return 1;
}

In this variant, I've replaced the constant digit 4 with sizeof(*zp) so that it becomes portable if the size of zp changes in future. Similarly the magic numbers 0,8,16,24 have been removed, that assumed a 4-bye size.
Instead a for loop is used that works for any size of zp. This makes it more readable and augments the flexibility of the changes applied to this function should your architecture become different in the future (more than 32 bits per example). Should also provide a tiny bit of performance improvements, in fact the reading of a uint32 from an array will be faster without having to shift and or.
For a non 'BTC_BIGENDIAN' machine that would result slower computation we've tried to minimise the computation avoiding shifting and or combination, benefited the memcpy() previously.