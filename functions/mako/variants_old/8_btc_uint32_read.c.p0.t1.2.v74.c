btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn < sizeof(uint32_t))
    return 0;
  
#if defined(BTC_BIGENDIAN)
  *zp = (((uint32_t)(*xp)[3] <<  0)
      | ((uint32_t)(*xp)[2] <<  8)
      | ((uint32_t)(*xp)[1] << 16)
      | ((uint32_t)(*xp)[0] << 24));
#else
#ifdef _MSC_VER
 // this block of code is added to handle case where the code compiled by MS Visual C/C++
  __declspec(safebuffers) //Buffer security check
  // help to prevent the common mistake of writing past the end of an array
  // incorporated into the code by the compiler
  memcpy_s(zp, sizeof(*zp), *xp, sizeof(*zp));
#else
  memcpy(zp, *xp, sizeof(*zp));
#endif
#endif

  *xp += sizeof(uint32_t);
  *xn -= sizeof(uint32_t);

  return 1;
}