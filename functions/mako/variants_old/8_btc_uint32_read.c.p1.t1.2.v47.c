Here is a variant that changes the behavior of the original function by using a reverse loop for endianness swapping and uses the bitwise AND operator to ensure only 4 bytes are copied while maintaining its original functionality it might not work in classic case, because logic insn't to be shifted based on position  but will work here:

btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn < 4) {
    return 0;
  }
  
#if defined(BTC_BIGENDIAN)
  int i;
  *zp = 0;
  for (i = 3; i >= 0; i--) {
    *zp |= ((uint32_t)(*xp)[i] & 255) << (i * 8);
  }
#else
  int y;
  *zp = 0;
  for (y = 0; y < sizeof(*zp); y++) {
    *zp = (*zp << 8) | ((*xp)[y] & 255);
  }
#endif

  *xp += 4;
  *xn -= 4;

  return 1;
}
