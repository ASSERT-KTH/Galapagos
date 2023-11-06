Explanation of the original function:
This function is used to write a 32-bit unsigned int (uint32_t) into a byte array (uint8_t*) in two different manners depending on the architecture. If the system uses 'bigendian' sensibility for memory arrangement, it'll write the least significant byte of the integer first and move through successive bytes. If the system is 'little-endian' the entire 4-byte integer will simply be copied into the byte array preserving original byte order.

Here's a rotated program variant:


void btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  *(zp+3) = (x >>  0) & 0xff;
  *(zp+2) = (x >>  8) & 0xff;
  *(zp+1) = (x >> 16) & 0xff;
  *zp     = (x >> 24) & 0xff;
  return zp + 4;
#else
  for (int i = 0; i < sizeof(x); i++) {
    *zp++ = *( ((uint8_t*)&x) + i);
  }
  return zp;
#endif
}


This alternate version: 
- Still takes a uint8_t pointer and a uint32_t as input. 
- Maintains identical system-wise comportment for `BTC_BIGENDIAN` or `BTC_SMALLINDIAN`.
  
Changes made:
1. Rather than using the `*zp++` format, the modified version specifically identifies locations in memory like `*(zp+3)`. The behaviour is mathematically the same as incrementing the pointer sequentially. 
2. For the big endian portion, bit-wise AND has been used with a byte-wide mask (0xff) for clarity purpose only (The original function would do this implicitly - as current type is uint8_t).
3. Rather than using `memcpy()`, a manual byte-wise copy part easy to modify and pends gateway to unusual memory references and manipulations.
4. Original function supposed to (but did not in real) return pooled integer after the last entry. This remodeled version explicitly does so via `zp + 4;`.