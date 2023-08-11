Here is a version of your function that maintains the original functionality:


btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  zp[0] = x >> 0;
  zp[1] = x >> 8;
  zp[2] = x >> 16;
  zp[3] = x >> 24;
  return zp + 4;
#else
  *(uint32_t*)zp = x;
  return zp + 4;
#endif
}


All this version does is write the bytes directly to the given pointer in the case of a big endian system, rather than incrementing the pointer, which could theoretically lead to memory access violations if you're not careful. For the little endian case, we're using pointer casting instead of memcpy, which should lead to a bit of a performance increase since it isn't calling a function. Note that Like the original version, This version also assume that zp points to an enough space to accommodate a uint32_t.