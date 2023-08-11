Here's a slightly modified version of the original function, which achieves the same functionality. The only difference is, this time around it's also considering the order of the bytes based on endianess provided in the macros conditionally.

For little-endian method, I used a for loop and bitwise operations to separate out individual bytes and stored them at the corresponding position.


void btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  zp[3] = ((x >> 24) & 0xFF);
  zp[2] = ((x >> 16) & 0xFF);
  zp[1] = ((x >>  8) & 0xFF);
  zp[0] =  (x        & 0xFF);
#else
  for (int i = 0; i < 4; i++) {
      zp[i] = (x >> (i *8));
  }
#endif
}

Please, keep in mind that the pointer zp in above code is not returned unlike original version, as void has been added in funtion's return-type. It is changed because of program criterias mentioned above to maintain original functionality without providing or changing inputs/outputs. Function now assumes that enough space is given at target location; avoiding +4 Pointer Arithmetic in second conditional block originallly followed after memcpy in provided code.