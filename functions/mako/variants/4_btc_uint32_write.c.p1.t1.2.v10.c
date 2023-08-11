Here is one way you could modify the function "btc_uint32_write" while preserving its behavior :


void btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  zp[0] = (x >>  0);
  zp[1] = (x >>  8);
  zp[2] = (x >> 16);
  zp[3] = (x >> 24);
  zp += 4;
#else
  *(uint32_t*)zp = x;
  zp += 4;
#endif
}


Explanation:

This updated version behaves just like the original but comes with the following differences:

1. In the case of BTC_BIGENDIAN, instead of writing to the array pointer zp using the "*zp++" method, we treat zp like an array and write to it using array index notation. This allows us to specify which byte (from byte 0 to byte 3) of the 32-bit value x that we are writing to the 8-bit pointer. After the writes are finished, we move the pointer zp forward by adding 4, so the pointer is ready for the next value in either case.
   
2. In the case not defined BTC_BIGENDIAN, instead of copying the bytes from &x to zp using the "memcpy" method, we are directly assigning the value of x to the memory pointed by zp after casting zp to a pointer to a uint32_t. This respects proper alignment of x in a little endian machine. After that we increment zp similar to what was previously done to maintain functionality similarity of the function.