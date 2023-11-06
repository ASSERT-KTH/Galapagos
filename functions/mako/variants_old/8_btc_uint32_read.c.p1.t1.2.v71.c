Here's another implementation of the same functionality, but using pointers and cast to directly retrieve uint32_t value in a little-endian system. Note that your function involves the processing of bitcoin related terminology so it requires the assumption around the endianness of data. Therefore, casting pointer to an integer, as shown in code, would only work for little-endian systems.


btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn < 4)
    return 0;

#if defined(BTC_BIGENDIAN)
  *zp = ((*xp)[3] << 24)
      | ((*xp)[2] << 16)
      | ((*xp)[1] << 8)
      | ((*xp)[0]);
#else
  *zp = *((uint32_t*) *xp); // Type cast to int pointer and take the value 
#endif

  *xp += 4;
  *xn -= 4;

  return 1;
}

When endianness is NOT known the usage of pointer raises issues as the order of 4 bytes in memory do matter. Therefore, explicit mapping as done in original code stands better universally.
The changes made specifically for "little-endianness" can lead to problems if run on a "big-endian" machine without changing BTC_BIGENDIAN as it meant for optimal execution on little-endian machine.