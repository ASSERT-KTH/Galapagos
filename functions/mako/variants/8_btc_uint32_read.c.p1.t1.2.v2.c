You can swap the if statement to a direct return to optimize the function slightly. The readability slightly decreases because the main flow is inside the condition itself not directly under the function scope, but functionality stays the same.


btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn >= 4) {

#if defined(BTC_BIGENDIAN)
    *zp = ((uint32_t)(*xp)[0] <<  0)
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
