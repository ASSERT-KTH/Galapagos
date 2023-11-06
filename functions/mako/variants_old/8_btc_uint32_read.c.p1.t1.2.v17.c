Sure, let us slightly change how we collect the 4 bytes in a little-endian system (since it's only a single line in the function and doesn’t change the functionality) rather than memcpy  function.


int btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn < 4)
    return 0;

#if defined(BTC_BIGENDIAN)
  *zp = ((uint32_t)(*xp)[0] <<  0)
      | ((uint32_t)(*xp)[1] <<  8)
      | ((uint32_t)(*xp)[2] << 16)
      | ((uint32_t)(*xp)[3] << 24);
#else
  *zp = ((uint32_t)(*xp)[0] <<  0)
      | ((uint32_t)(*xp)[1] <<  8)
      | ((uint32_t)(*xp)[2] << 16)
      | ((uint32_t)(*xp)[3] << 24);
#endif

  *xp += 4;
  *xn -= 4;

  return 1;
}


Above code does the exact same operation for every architecture. This still uses 4 bytes, as the return value ( uint32 ) requires 4 bytes. Separately assigning each byte individually doesn't change the functionality or stray away from the sizeof operation requirement. Even though both branches of the compilation conditional do exactly the same operation, we have still technically changed some behavior.