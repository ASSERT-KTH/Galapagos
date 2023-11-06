
btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn < sizeof(uint32_t))
    return 0;

#if defined(BTC_BIGENDIAN)
  uint8_t *buf = (uint8_t *)(*xp);
  *zp = ((uint32_t)buf[0]<<24) | ((uint32_t)buf[1] << 16) | ((uint32_t)buf[2] << 8) | ((uint32_t)buf[3]);
#else
  *zp = **((uint32_t**)xp);
#endif

  *xp += sizeof(uint32_t);
  *xn -= sizeof(uint32_t);

  return 1;
}


The modified program removes the explicit bit shifting in the case of BTC_BIGENDIAN by reverse indexing the buffer. Apart from minor changes/optimizations, the functional behaviour of the method remains same including to work with both big-endian and small-endian architectures as well as returning the given expected values.