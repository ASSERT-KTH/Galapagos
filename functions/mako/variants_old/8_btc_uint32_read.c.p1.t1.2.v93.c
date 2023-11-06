The variant program could be like so.


btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn < sizeof(uint32_t))
    return 0;

#if defined(BTC_BIGENDIAN)
  uint8_t *temp = (uint8_t *)zp;
  *temp       = *((*xp) + 3);
  *(temp + 1) = *((*xp) + 2);
  *(temp + 2) = *((*xp) + 1);
  *(temp + 3) = **xp;
#else
  *zp = **((uint32_t **)xp);
#endif

  *xp += sizeof(uint32_t);
  *xn -= sizeof(uint32_t);

  return 1;
}


The above solution basically maintains the same functionality while changing the original practical workflow. In the big-endian section, it changes the original bulk bit operation into a byte-by-byte copying.

It assumes that the pointer `xp` directly point to a continuous buffer, and the beginning 4 part of the buffer storage bytes of `uint32` big-endian number.

Similar assumption also applies to the non-big-endian part. It just interprets `xp` as the address of a `uint32_t` value, then derefferences it, and copies to the place `zp` refers to. If the assumption does not break, the action behaves the same way as `memcpy`.