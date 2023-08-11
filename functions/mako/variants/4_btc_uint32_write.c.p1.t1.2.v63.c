
void btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  zp[0] = (x >>  0) & 0xFF;
  zp[1] = (x >>  8) & 0xFF;
  zp[2] = (x >> 16) & 0xFF;
  zp[3] = (x >> 24) & 0xFF;
#else
  uint8_t *xp = (uint8_t*)&x;  
  zp[0] = xp[0];
  zp[1] = xp[1];
  zp[2] = xp[2];
  zp[3] = xp[3];
#endif
}
 

The adapted function is basically doing the same thing but there are differences that can be mentioned:
1. Rather than incrementing the pointer after each write operation, the adapted function uses array indexing to reach each byte location. This makes the code easier to interpret at a glance, as it is immediately clear what byte each operation corresponds to.
   
2. Big-Endian implementation: The adapted function adds "& 0xFF" after each shift operation. This bitwise AND operation ensures that only the 8 least significant bits are extracted and made place into the uint8_t variable, providing explicit masking. While suggesting good practices, this operation is actually superfluous in context as the values would be implicitly downcast when assigned to uint8_t variables anyway.

3. Little-Endian implementation: While the original function simply copies the uint32_t value into the destination uint8_t array using the memcpy function, describing its actions broadly as copying 'sizeof(x)' bytes worth of data, the adapted function details the copy operation byte by byte making it clearer to understand what exactly is happening. The equivalent manual operation makes it more explicit that they work by simply reinterpreting the bit pattern as a sequence of bytes rather than it being some kind of conversion.