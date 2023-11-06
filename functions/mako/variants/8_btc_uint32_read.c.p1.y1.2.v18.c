Here are a few varied implements of the above function:

Implementation 1:
The implementation checks whether *xn < 4 and processes the *xp pointer then modifies the *xp and *xn accordingly.


btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn < sizeof(*zp))
    return 0;

#if defined(BTC_BIGENDIAN)
  *zp = ((uint32_t)((*xp)[0]) 
      | (((uint32_t)((*xp)[1])) << 8) 
      | (((uint32_t)((*xp)[2])) << 16) 
      | (((uint32_t)((*xp)[3])) << 24));
#else
  *zp = *((uint32_t*)*xp);
#endif

  *xp += sizeof(*zp);
  *xn -= sizeof(*zp);

  return 1;
}


Implementation 2:
Here, the functionality remains the same while the layout has slight modifications for easier understanding:


btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn < 4)
    return 0;

#if defined(BTC_BIGENDIAN)
  *zp = ((*xp)[0] 
  | ((*xp)[1] << 8) 
  | ((*xp)[2] << 16) 
  | ((*xp)[3] << 24));
#else
  memcpy(zp, *xp, sizeof(*zp));
#endif
  (*xp) += sizeof(*zp);
  (*xn) -= sizeof(*zp);

  return 1;
}


Implementation 3:
This implementation particularly uses bitwise shift operations for non-BTC_BIGENDIAN part as well.


btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn < 4)
    return 0;

#if defined(BTC_BIGENDIAN)
  *zp = ((*xp)[0] 
  | ((*xp)[1] << 8) 
  | ((*xp)[2] << 16) 
  | ((*xp)[3] << 24));
#else
  *zp = ((*xp)[0] 
  | ((*xp)[1] << 8) 
  | ((*xp)[2] << 16) 
  | ((*xp)[3] << 24));
#endif
  *xp += 4;
  *xn -= 4;

  return 1;
}
