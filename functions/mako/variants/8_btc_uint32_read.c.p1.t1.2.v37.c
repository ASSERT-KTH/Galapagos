
btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn < sizeof(uint32_t))
    return 0;

#if defined(BTC_BIGENDIAN)
  uint32_t value = 0;
  for (size_t i = 0; i < sizeof(uint32_t); i++) {
    value |= ((uint32_t)(*xp)[i] << 8 * i);
  }
  *zp = value;
#else
  uint8_t *zp_byte = (uint8_t*)zp;
  for (size_t i = 0; i < sizeof(uint32_t); i++) {
    zp_byte[i] = (*xp)[i];
  }
#endif

  *xp += sizeof(uint32_t);
  *xn -= sizeof(uint32_t);

  return 1;
}

In this variant of your code, I replaced the hard-coded 4 with `sizeof(uint32_t)`, so it'll still work if the size of `uint32_t` is changed in the future. Also, I used loops to read bytes one at a time in the big and little endian branches of the code.

Unlike your original "big endian" code counterpart, the new code in the loop now works even when bytes higher than the third are part of your value. The original code works for four byte values, while the new code works for `uint32_t`s of any size that also happen to have only four bytes with nonzero value.

Also, the new "little endian" branch now pointer-casts `zp` to a `uint8_t*` and copies bytes one at a time instead of calling `memcpy`. This produces the similar result as that of `memcpy`, however, memcpy generally has some optimizations so the one by one copying might be slower.