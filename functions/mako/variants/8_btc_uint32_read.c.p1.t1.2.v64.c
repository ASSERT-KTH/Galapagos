Sure here is a variant. I swapped the code blocks used for big-endian and little-endian data and reworked the code for the little-endian case:


btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn < 4)
    return 0;

#if defined(BTC_BIGENDIAN)
   memcpy(zp, *xp, sizeof(*zp));
#else
  *zp = ((uint32_t)(*xp)[0] << 24)
      | ((uint32_t)(*xp)[1] << 16)
      | ((uint32_t)(*xp)[2] << 8)
      | ((uint32_t)(*xp)[3] << 0);
#endif

  *xp += 4;
  *xn -= 4;

  return 1;
}

This version maintains the original functionality but the blocks of codes for handling big-endian and little-endian data have been interchanged: the "memcpy" function call is now in the block for big-endian data and the  bitwise operations have been moved to the block that handles little-endian data. It's important to note that while this little-endian code will technically compile and function correctly, it is doing unnecessary work as the bitwise shift and OR operations are not necessary for a little-endian system. On a little-endian system, you does not need to "rearrange" the bytes using bitwise shift operations as how it's needed for a big-endian system.