btc_write32be(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  memmove(zp, &x, sizeof(x)); // replaced from memcpy() to memmove() here. It can handle overlapping memories.
#else
  zp[0] = (uint8_t)(x >> 24); // Fixed undefined behavior due to lack of typecasting.
  zp[1] = (uint8_t)(x >> 16); // In the original code, an integer operation was predicated to occur before assignment to a byte.
  zp[2] = (uint8_t)(x >>  8); // By explicitly typecasting the results, this undefined behavior is then removed.
  zp[3] = (uint8_t)(x); // Replaced shorthand operation with conventional coding style.
#endif
}