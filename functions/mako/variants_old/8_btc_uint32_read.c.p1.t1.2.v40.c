Here is a slightly altered version of the function. It packs the operation of incrementing/decrementing *xp and *xn inside a compound statement and uses BASE_ENDIAN macros for byte swapping different to BTC_BIGENDIAN. But functional-wise it remains unchanged:


btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn < 4)
    return 0;

#if defined (BASE_BIGENDIAN)
  *zp = (*xp)[0] | ((*xp)[1] << 8) | ((*xp)[2] << 16) | ((*xp)[3] << 24);
#else
  *zp = (*xp)[3] | ((*xp)[2] << 8) | ((*xp)[1] << 16) | ((*xp)[0] << 24);
#endif

  (
    void)(*xp += 4),
    void)(*xn -= 4)
  );

 return 1;
}
