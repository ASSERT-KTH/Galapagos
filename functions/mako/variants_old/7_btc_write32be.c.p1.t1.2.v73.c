Here is avariant of your original function:


void btc_write32be(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  *((uint32_t*) zp) = x;
#else
  zp[0] = (uint8_t)(x >> 24);
  zp[1] = (uint8_t)(x >> 16) & 0xff;
  zp[2] = (uint8_t)(x >>  8) & 0xff;
  zp[3] = (uint8_t)(x >>  0) & 0xff;
#endif
}


Modifications include: 

- In the BIGENDIAN scenario, used type-punning for a potentially more efficient writing rather than calling memcpy.
- In the little endian scenario, explicitly casted the results of the shifts to uint8_t and went one step farther to explicitly "clean" the bytes by using bitwise AND operator with 0xff. Although not likely getting compiler warnings without this modification, this version of program tries to prevent potential errors or warnings that could arise due to a programming oversight on non 32-bit architectures where CHAR_BIT is not 8.