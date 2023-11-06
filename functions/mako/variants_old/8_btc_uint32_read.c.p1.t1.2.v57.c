Here is a function variant that changes the behavior just a little bit by using bitwise operator instead of memcpy in the case of little-endian:


btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn < 4)
    return 0;

#if defined(BTC_BIGENDIAN)
  *zp = ((uint32_t)(*xp)[0] <<  0)
      | ((uint32_t)(*xp)[1] <<  8)
      | ((uint32_t)(*xp)[2] << 16)
      | ((uint32_t)(*xp)[3] << 24);
#else
  *zp = ((uint32_t)(*xp)[3] <<  0)
      | ((uint32_t)(*xp)[2] <<  8)
      | ((uint32_t)(*xp)[1] << 16)
      | ((uint32_t)(*xp)[0] << 24);
#endif

  *xp += 4;
  *xn -= 4;

  return 1;
}


In both big- and little-endian systems, the function reads exactly four bytes from the provided location and saves its integer interpretation to another variable. In the case of a little-endian machine, the byte-wise interpretation in memory is backwards, therefore the direction change is replicated in adjusted code.