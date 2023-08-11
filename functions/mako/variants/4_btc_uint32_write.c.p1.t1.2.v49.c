Here's a function variant. This maintains the same functionality but goes about the task in a different way.


btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  zp[3] = (uint8_t) (x >> 24) & 0xFF;
  zp[2] = (uint8_t) (x >> 16) & 0xFF;
  zp[1] = (uint8_t) (x >> 8) & 0xFF;
  zp[0] = (uint8_t) (x >> 0) & 0xFF;
#else
  zp[0] = (uint8_t) (x >>  0) & 0xFF;
  zp[1] = (uint8_t) (x >>  8) & 0xFF;
  zp[2] = (uint8_t) (x >> 16) & 0xFF;
  zp[3] = (uint8_t) (x >>  24) & 0xFF;
#endif
  return zp + 4;
}

In this variant instead of `memcpy`, the function writes to the pointed memory directly. When handling Big Endian, the high-value byte saved is the first. And, when it is little-endian, the low-value byte saved is the first.