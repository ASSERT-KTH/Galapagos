Here is a program variant that maintains the functionality of the original function while making use of bit shifting and typecasting even for little-endian systems:


btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn < 4)
    return 0;

#if defined(BTC_BIGENDIAN)
  *zp = ((uint32_t)(*xp)[0] <<  0)
        | ((uint32_t)(*xp)[1] <<  8)
        | ((uint32_t)(*xp)[2] << 16)
        | ((uint32_t)(*xp)[3] << 24);
#else
  *zp = ((uint32_t)(*xp)[0])
        | ((uint32_t)(*xp)[1] << 8)
        | ((uint32_t)(*xp)[2] << 16)
        | ((uint32_t)(*xp)[3] << 24);
#endif

  *xp += 4;
  *xn -= 4;

  return 1;
}


This version uses bit manipulation techniques (`<<`, bitwise rotation and `|`, bitwise OR) to construct the `uint32_t` `zp` byte by byte in both cases. It handles big and little-endian systems in the same manner except for the byte order. For big-endian sequences when `BTC_BIGENDIAN` is defined, the bytes are arranged from most significant (MSB at higher memory address) to least significant (LSB at lower memory address), otherwise for little-endian `<=> little-end=low-end=less significant endian`.

It is important to note that the algorithm is now dependent on the endianness assuming that the bytes are saved with least significant byte first natively (`explicit little-endian` as opposed to clear-native `implicit little-endian`) which in practice varies with different systems used. Original version with memcpy could ensure the correct byte order irrelevant of input data source since the explicit byte order mentioned below is only considered if BTC_BIGENDIAN is defined.