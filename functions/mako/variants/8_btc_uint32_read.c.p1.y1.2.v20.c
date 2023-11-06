Variant 1: Removed the if-else condition related to endianess. This transformation assumes a certain type of hardware, particularly a little-endian.


btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn < 4)
    return 0;

  memcpy(zp, *xp, sizeof(*zp));

  *xp += 4;
  *xn -= 4;

  return 1;
}


Variant 2: Consolidate increment towards the end. This changes the order of instructions without altering the behaviour logic.


btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn < 4)
    return 0;

#if defined(BTC_BIGENDIAN)
  *zp = ((uint32_t)(*xp)[0] <<  0)
      | ((uint32_t)(*xp)[1] <<  8)
      | ((uint32_t)(*xp)[2] << 16)
      | ((uint32_t)(*xp)[3] << 24);
#else
  memcpy(zp, *xp, sizeof(*zp));
#endif

  *xn -= 4;
  *xp += 4;

  return 1;
}


Variant 3: Consolidate updating of *xp and *xn to the middle of the function before returning based on read status.


btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn < 4)
    return 0;

  *xp += 4;
  *xn -= 4;

#if defined(BTC_BIGENDIAN)
  *zp = ((uint32_t)(*xp)[0] <<  0)
      | ((uint32_t)(*xp)[1] <<  8)
      | ((uint32_t)(*xp)[2] << 16)
      | ((uint32_t)(*xp)[3] << 24);
  return 1;
#else
  if (memcpy(zp, *xp, sizeof(*zp)))
    return 1;
  else
    return 0;
#endif
}
