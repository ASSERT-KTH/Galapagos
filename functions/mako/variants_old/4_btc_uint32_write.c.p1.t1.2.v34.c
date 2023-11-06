
btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  zp[0] = (x >>  24);
  zp[1] = (x >>  16);
  zp[2] = (x >>  8);
  zp[3] = (x >>  0);
  return zp + 4;
#else
  zp[0] = x & 255;
  zp[1] = (x >> 8) & 255;
  zp[2] = (x >> 16) & 255;
  zp[3] = (x >> 24) & 255;
  return zp + 4;
#endif
}

This version does the same thing but uses array indexing instead of pointer arithmetic to write the bytes into the buffer. This can make the code a bit clearer for some readers. I swapped the byte order for the big-endian case to match the original implementation's possible little-endian order.
Please be aware that the two functions are not functionally identical on all platforms. Some processors don't allow you to read from or write to addresses that are not aligned with 4-byte boundaries and it is possible that `zp` is not a 4-byte aligned address in these function calls; considering which, memcpy approach can be impractical in those conditions. For this reason, clarify specifically the system architecture where you'd be calling these function.