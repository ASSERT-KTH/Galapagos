The following piece of code comes successful when we consider to continue the work of the above detailed function code by maintaining their overall function.


void btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  *zp++ = (uint8_t)(x & 0xFF);
  x >>= 8;
  *zp++ = (uint8_t)(x & 0xFF);
  x >>= 8;
  *zp++ = (uint8_t)(x & 0xFF);
  x >>= 8;
  *zp++ = (uint8_t)(x & 0xFF);
#else
  *zp++ = (uint8_t)(x & 0xFF);
  x >>= 8;
  *zp++ = (uint8_t)(x & 0xFF);
  x >>= 8;
  *zp++ = (uint8_t)(x & 0xFF);
  x >>= 8;
  *zp++ = (uint8_t)(x & 0xFF);
#endif
}

This implementation clearly shows different handling ways for big-endian and little-endian architectures but still uses the bitwise shifts and 'and' operations for getting the individual bytes out of uint32_t. Difference to the reference implementation is only how those bytes are copied, this option does not even include functions such as memcpy but uses only similar base level operations and therefore more feasible to get consistent results on all platforms.