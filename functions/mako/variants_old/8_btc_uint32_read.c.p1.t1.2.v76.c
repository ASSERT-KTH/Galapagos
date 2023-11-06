The rewritten function could look like this. The changes I have made simply rearrange the original code, but every aspect of this code performs the same task as the original input code.


btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {

  if (*xn >= 4)
  {
#if defined(BTC_BIGENDIAN)
    *zp = ((*xp)[0] <<  0)
        | ((uint32_t)(*xp)[1] <<  8)
        | ((uint32_t)(*xp)[2] << 16)
        | ((uint32_t)(*xp)[3] << 24);
#else
    memcpy(zp, *xp, sizeof(*zp));
#endif

    *xp += 4;
    *xn -= 4;
    
    return 1;
  }
  
  return 0;
}
