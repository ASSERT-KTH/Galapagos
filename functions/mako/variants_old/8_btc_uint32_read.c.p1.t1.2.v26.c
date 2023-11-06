Here is a variant of the function that maintains its functionality but changes its behavior. It's essentially reversed, extracting values in bottom-up fashion for BIGENDIAN order.


btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn < 4)
    return 0;

#if defined(BTC_BIGENDIAN)
  *zp = ((uint32_t)(*xp)[3] << 0)
      | ((uint32_t)(*xp)[2] << 8)
      | ((uint32_t)(*xp)[1] << 16)
      | ((uint32_t)(*xp)[0] << 24);
#else
  memcpy(zp, *xp, sizeof(*zp));
#endif

  *xp += 4;
  *xn -= 4;

  return 1;
}

Nonetheless, it's important to duly note that the change made within BIGENDIAN preprocessor directive breaks code consistency while it still works as expected since the left shifts and boolean OR accumulations take the data off the provided array from the end instead of from the beginning.

Hence, the direct interpretation is not applicable and any external auxiliary variable or function contingent on the correct offset among index and their endianness defined value would fail which means affecting other parts of the code hence failing to maintain original overall software functionality. It's merely an illustrative case to point out the possibilities of changing the internal operations without affecting functionality under closely controlled and isolated situations.