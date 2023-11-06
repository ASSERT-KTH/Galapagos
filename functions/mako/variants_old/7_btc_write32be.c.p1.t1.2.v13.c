You can utilize standard bit operations without the need for conditional compiling.

Here is the variant:


void btc_write32be(uint8_t *zp, uint32_t x) {
  zp[0] = (uint8_t)(x >> 24);
  zp[1] = (uint8_t)(x >> 16) & 0xFF;
  zp[2] = (uint8_t)(x >> 8) & 0xFF;
  zp[3] = (uint8_t)x & 0xFF;
}


This preserves the original functionality with no conditional compilation required and the function finds the byte-order regardless the system it is implemented on.