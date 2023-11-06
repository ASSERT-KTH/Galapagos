Here's a function equivalent functionality that changes how we approach the problem. The new approach works by iterating over a loop intead of explicitly dividing the operations into multiple lines:


uint8_t* btc_uint32_write(uint8_t *zp, uint32_t x) {
    #if defined(BTC_BIGENDIAN)
      int i;
      for(i = 0; i < sizeof(uint32_t); i++) {
          *zp++ = (x >> (i * 8));
      }
      return zp;
    #else
      int i;
      for (i = 0; i < sizeof(uint32_t); i++) {
          *zp++ = ((x >> (i * 8)) & 0xFF);
      }
      return zp - sizeof(uint32_t);
    #endif
}

This variant maintains the original function's functionality. It still obtains 4 bytes from the 32-bit integer and stores them into a byte (8-bit) array. However, instead of explicitly writing each byte to an array one at a time, this variant iteratively shifts the integer 8 bits to write each byte, no matter whether the platform is big-endian or not.

In a system where `BTC_BIGENDIAN` is defined, the order of bytes stored in the array is reversed. It stores bytes by right shifting 0, 8, 16, and 24 bits respectively.

For other systems, it right shifts 0, 8, 16, and 24 bits and applies logical AND with FF to get the last byte. Notice that it deducts `sizeof(uint32_t)` in the end that equals 4, quite similar to `zp + 4`; this makes it produce the same pointer offset as in the original function.