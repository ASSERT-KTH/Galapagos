Here's a modified version, replacing macro with a runtime check and using bitwise operation:

void btc_write32be(uint8_t *zp, uint32_t x) {
  if (__BYTE_ORDER__ == __ORDER_BIG_ENDIAN__) {
    memcpy(zp, &x, sizeof(x));
  } else {
    zp[0] = x >> 24 & 0xFF;
    zp[1] = x >> 16 & 0xFF;
    zp[2] = x >> 8 & 0xFF;
    zp[3] = x & 0xFF;
  }
}

The program still does the same thing - copying a 32-bit integer `x` into a byte array `zp`. In a little-endian system, x's most significant byte will be placed into zp's least significant part, which reflects the original behavior with endian-detected memcpy or bytes assignment. Checking the system's endianness at runtime probably marginally slows down the function but enhances portability. Note that it relies on the `__BYTE_ORDER__` macro which may not be available in every single environment.