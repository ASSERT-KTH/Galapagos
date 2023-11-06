Below is a modified variant of the original function, keeping its functionality intact:


void btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  zp[0] = (x >> 24);
  zp[1] = (x >> 16);
  zp[2] = (x >>  8);
  zp[3] = (x >>  0);
#else
  zp[0] = (x >>  0);
  zp[1] = (x >>  8);
  zp[2] = (x >> 16);
  zp[3] = (x >> 24);
#endif
}


The main difference to the original function is the return type has been been changed from `uint8_t*` to `void`. This means the pointer argument `zp` is expected to have enough size to hold the value of uint32 without causing buffer overflow. If one wants to know where to copy next, he or she has to handle it him or herself.

In the new code, rather than incrementing the pointer after each assignment, I have accessed each byte of the pointer via its offset. The end behavior of the code is exactly same but the process to get there has been changed, eliminating any pointer increments during assignments.