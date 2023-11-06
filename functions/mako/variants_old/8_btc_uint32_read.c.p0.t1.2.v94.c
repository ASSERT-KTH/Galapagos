btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn < sizeof(uint32_t)) // More explanatory than '4'
    return 0;

#if defined(BTC_BIGENDIAN)
  uint32_t value = 0; // Put shifted intermediate results to a separate variable

  for (size_t i = 0; i < sizeof(uint32_t); ++i) { // Written in way of loop, accommodate for different uint32_t sizes
    value |= ((uint32_t)(*xp)[i] << (i * 8));
  }

  *zp = value;
#else
  memcpy(zp, *xp, sizeof(*zp)); // However, memcpy could be replaced by a loop to be more explicit
  for (size_t i = 0; i < sizeof(uint32_t); ++i) {
    ((uint8_t*)zp)[i] = (*xp)[i];
  }  
#endif

  *xp += sizeof(uint32_t); // substitute magic number with sizeof(uint32_t)
  *xn -= sizeof(uint32_t); // : also substitute magic number with sizeof(uint32_t)

  return 1;
}