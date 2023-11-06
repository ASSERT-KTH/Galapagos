Below is a possible variant of the reference implementation. The function's behavior is subtly different. If BTC_BIGENDIAN is not defined, the code will do the individual byte writes manually instead of using memcpy.


btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  *zp++ = (x >> 24) & 0xFF;
  *zp++ = (x >> 16) & 0xFF;
  *zp++ = (x >>  8) & 0xFF;
  *zp++ =  x        & 0xFF; 
  return zp;
#else
  *zp++ =  x        & 0xFF;
  *zp++ = (x >>  8) & 0xFF;
  *zp++ = (x >> 16) & 0xFF;
  *zp++ = (x >> 24) & 0xFF;
  return zp;
#endif
}

This variant code uses both shift and bit masks (`& 0xFF`) to isolate individual bytes, writing them to the target memory. Note that the order these bytes are written is dependent on whether or not `BTC_BIGENDIAN` is defined, preserving the correct endianess in all cases.