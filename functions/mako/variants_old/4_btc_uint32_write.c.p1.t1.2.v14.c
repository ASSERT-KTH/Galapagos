Here's a variation of the original function that maintains the same functionality but changes how it achieved:


btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  zp[0] = (x >>  0) & 0xFF;
  zp[1] = (x >>  8) & 0xFF;
  zp[2] = (x >> 16) & 0xFF;
  zp[3] = (x >> 24) & 0xFF;
  return zp + sizeof(x);
#else
  zp[0] = x & 0xFF;
  zp[1] = (x >> 8) & 0xFF;
  zp[2] = (x >> 16) & 0xFF;
  zp[3] = (x >> 24) & 0xFF;
  return zp + sizeof(x);
#endif
}


The function shifts bits to the right and uses bit-wise AND to mask the lower 8 bits. This change keeps identical behavior but performs breakdown of `uint32_t x` into `uint8_t` parts manually in case of both big endian and little endian systems removing the use of `memcpy`. It still work on 4 bytes at a time. Therefore, for big endian, shifting starts at 0 and for little endian, shifting starts from low byte to high. The result remains equivalent to the original function.
