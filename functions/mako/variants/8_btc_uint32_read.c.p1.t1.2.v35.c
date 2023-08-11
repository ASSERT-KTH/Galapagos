Here is a version of the function which achieves the same functionality, but changes the behaviour by utilising a union type to perform the byte manipulation:


btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn < 4) 
    return 0;

  union {
    uint32_t u32;
    uint8_t arr[4];
  } u;

#if defined(BTC_BIGENDIAN)
  u.arr[0] = (*xp)[3];
  u.arr[1] = (*xp)[2];
  u.arr[2] = (*xp)[1];
  u.arr[3] = (*xp)[0];
  *zp = u.u32;
#else
  memcpy(u.arr, *xp, sizeof(u.arr));
  *zp = u.u32;
#endif

  *xp += 4;
  *xn -= 4;

  return 1;
}
 
In this variant, the code utilises a union that consists of an unsigned 32 bit integer and a 4 element byte array. For both ENDIAN types, the code first copies the values to the byte array of the union. For BIGENDIAN type, it orders the bytes in reverse direction and then writes it back to the uint32 reference. For LITTLEENDIAN (e.g if not defined BIGENDIAN) it directly performs a memcpy.
It serves the same function as original piece of code, but changes the way how it operates. 

Note: Be mindful about old or non-standard compliant C compilers base on byte order of two types mentioned in union, which can lead to different behavior.
