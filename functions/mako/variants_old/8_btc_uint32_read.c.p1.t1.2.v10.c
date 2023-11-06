The following code offers a different approach to implement the same functionality:


btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {

  if (*xn < sizeof(*zp))
    return 0;
  
#if defined(BTC_BIGENDIAN)
  uint8_t *p = (uint8_t *) zp;
  p[0] = (*xp)[0];
  p[1] = (*xp)[1];
  p[2] = (*xp)[2];
  p[3] = (*xp)[3];
#else
  *zp = (*((uint32_t*)*xp));
#endif

  *xp += sizeof(*zp);
  *xn -= sizeof(*zp);

  return 1;
}

Here the #if defined(BTC_BIGENDIAN) and #else parts where originally separated do the same task. The value zp points to is loaded with the first 4 bytes from the memory area xp points to, in bigendian or non-bigendian manner correspondingly. Moreover, the update of the xp pointer and the decrease of the size is done exactly as in the original function. The original inside conditions are based on uint8_t manipulations regardless of the system, meanwhile the changed version works based on uint32_t instead.