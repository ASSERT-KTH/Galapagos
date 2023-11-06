Here is an acceptable alternative using an intermediate buffer:


btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn < 4)
    return 0;

  uint32_t buffer = 0;

#if defined(BTC_BIGENDIAN)
  buffer = ((uint32_t)(*xp)[0] <<  0)
         | ((uint32_t)(*xp)[1] <<  8)
         | ((uint32_t)(*xp)[2] << 16)
         | ((uint32_t)(*xp)[3] << 24);
#else
  memcpy(&buffer, *xp, sizeof(buffer));
#endif

  *zp = buffer;

  *xp += 4;
  *xn -= 4;
  
  return 1;
}


This variant works by reading from the pointer `*xp` into the buffer, capable of handling big endian systems manually with a bitwise shift or for little endian using `memcpy`. After reading the value, the code then copies the value into `*zp`. Lastly, the function increments the pointers and decrements the size accordingly.