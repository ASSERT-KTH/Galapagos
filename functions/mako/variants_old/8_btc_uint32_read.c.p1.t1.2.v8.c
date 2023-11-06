Sure, the following solution will maintain same functionality while adding one additional performance optimality i.e. checking endianness at compile time:


btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn < 4)
    return 0;

  union EndianCheck {
    uint32_t i;
    char c[4];
  } endianCheck = {0x01000000};

  if (endianCheck.c[0]) {
    *zp = ((uint32_t)(*xp)[0] <<  0)
        | ((uint32_t)(*xp)[1] <<  8)
        | ((uint32_t)(*xp)[2] << 16)
        | ((uint32_t)(*xp)[3] << 24);
  } else {
    memcpy(zp, *xp, sizeof(*zp));
  }

  *xp += 4;
  *xn -= 4;

  return 1;
}


In the above code, I am using union-based endianness check that works on both compile-time and runtime. While running the method it won't run the union code on every method call rather only once then the corresponding instruction will be fixed in ASM by the OS This also removes the need for #if-defined/BTC_BIGENDIAN directive, thus maintaining original functionality where `zp` gets memory from `xp` and `xp`,`xn` incremented and decremented by 4 respectively if enough memory is present.

"Endianness" relates to how a system stores and retrieves data in its memory - which of the most and least significant byte of memory is retrieved before the other.