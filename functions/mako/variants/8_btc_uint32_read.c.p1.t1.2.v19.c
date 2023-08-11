Here's a variation to keep the original functionality intact while also changing the code. This alternative version uses array indexing for copying from the source.


btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
    if (*xn < 4)
      return 0;

  #if defined(BTC_BIGENDIAN)
    *zp = ((uint32_t)(*xp)[0] <<  0)
        | ((uint32_t)(*xp)[1] <<  8)
        | ((uint32_t)(*xp)[2] << 16)
        | ((uint32_t)(*xp)[3] << 24);
  #else
    // Instead of using memcpy, use explicit array indexing
    (*zp) = 0;
    (*zp) |= (*xp)[3] << 24;
    (*zp) |= (*xp)[2] << 16;
    (*zp) |= (*xp)[1] << 8;
    (*zp) |= (*xp)[0];
  #endif

    *xp += 4;
    *xn -= 4;

    return 1;
}


This snippet still uses the shift operator to manually perform the byte-by-byte copy, providing the same functionality as the memcpy() function. This change doesn’t alter any behavior of the function in the process space it was given to operate on; it merely does the work in a slightly different way. Your program should behave the same.