Since this function reads a 32-bit integer (4 bytes) from a byte array, checks that there are at least 4 bytes to read, updates the input pointer and the remaining byte count, based on the switching behaviour between little-endian and big-endian machines. A simple variant could translate all its C Preprocessor directive constraints (line with #-leading symbols) manually during execution regarding the underlying architecture, while still retaining its original functionality.
In the presented variant, a temporary variable, is used to avoid needing to modify *xp and *xn in the case *xn < 4. A check determines the system endianness during runtime and acts accordingly: reading four bytes little-endian or big-endian:

void btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn < 4) return 0;

  const uint8_t *p = *xp;
  uint32_t v;

  int is_big_endian = !(*(uint8_t *)&(uint16_t){1});

  if(is_big_endian){
      v = (uint32_t)p[3]
           | ((uint32_t)p[2] << 8)
           | ((uint32_t)p[1] << 16)
           | ((uint32_t)p[0] << 24);
  } else{
       v = (uint32_t)p[0]
           | ((uint32_t)p[1] << 8)
           | ((uint32_t)p[2] << 16)
           | ((uint32_t)p[3] << 24);
  }
  
  *zp = v;
  *xp += 4;
  *xn -= 4;

  return 1;
}

This version first checks system endianness by writing a 16-bit value with the lower of its two bytes set (the others are zero), and then reads the smallest, or lowest addressed, byte. If this initial write was a one, then we are in a little-endian platform (implying "false" or not big-endian), else, it seems true indicates big-endian.
Following pieces offer identical functionality as initial function, such as returning zero on insufficient byte consultation, or handling four subsequent bytes from original pointer preserving architecture's correct sequence of extraction for fulfilling higher-prioritized bits of the unsigned integer. Operations like shifting and bit-wise-insertions are identical.
Adjustments related to pointer content and count are also the original ones (line (*xp += 4; *xn -= 4;), addressing formerly observed equation four byte usage. Then, returns 1 meaning int32 complete constitution through given U8-byte pattern-wise unconstruction.