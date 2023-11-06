Sure, the below function should provide the same functionality as the preceding code while introducing some variance. I have wrapped the functionality into conditional blocks allowing there to be runtime configuration of behavior depending on whether a system supports memcpy or is defined as BIGENDIAN.


btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn < sizeof(uint32_t))
    return 0;

#ifdef CAN_MEMCPY
  memcpy(zp, *xp, sizeof(*zp));
#else
  #ifdef BTC_BIGENDIAN
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
#endif  

  *xp += sizeof(uint32_t);
  *xn -= sizeof(uint32_t);

  return 1;
}


Here, the function will use `memcpy` if `CAN_MEMCPY` is defined. If not, It will decode 32-bit integers as either big-endian or little-endian based on the `BTC_BIGENDIAN` flag. In the absence of all relevant flags, the system defaults to little-endian as a last resort.
Remember that `sizeof(uint32_t)` is always 4 in systems that support it, however, using `sizeof` makes it platform and compiler independent code as the byte size of standard integer types can vary between different architecture and compilers.