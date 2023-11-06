The function btc_read32le(const uint8_t *xp) reads a 32 bit integer in little-endian format from the array (*xp). Here's a variant that only changes code conditionally compiled for BTC_BIGENDIAN, but uses the same operation:


btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  return ((uint32_t)xp[3])
       | ((uint32_t)xp[2] << 8)
       | ((uint32_t)xp[1] << 16)
       | ((uint32_t)xp[0] << 24);
#else
  uint32_t z;
  // Moved each byte of xp into z independently
  ((uint8_t *)&z)[0] = xp[0];
  ((uint8_t *)&z)[1] = xp[1];
  ((uint8_t *)&z)[2] = xp[2];
  ((uint8_t *)&z)[3] = xp[3];
  return z;
#endif
}

Note that for non-BTC_BIGENDIAN case, instead of using memcpy to copy all 4 bytes at once, we copy each individual byte while maintaining the same functionality.