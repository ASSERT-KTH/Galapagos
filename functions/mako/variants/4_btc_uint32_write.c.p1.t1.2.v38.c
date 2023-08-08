The program code below is a variant of the original function. It maintains the original functionality goal of the function which is to write a 32-bit integer to a byte array (ZP). The change of behavior lies in how the least significant byte is saved in the first byte of the sequence and then progressing forward to the most significant byte last.


btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  *zp++ = (x >> 24);
  *zp++ = (x >> 16);
  *zp++ = (x >>  8);
  *zp++ = (x >>  0);
  return zp;
#else
  union {
    uint32_t number;
    uint8_t bytes[4];
  } un;
  
  un.number = x;

  *zp++ = un.bytes[3];
  *zp++ = un.bytes[2];
  *zp++ = un.bytes[1];
  *zp++ = un.bytes[0];

  return zp;
#endif
}

In the case where the byte order is little endian, a common characteristic of systems derived from the Intel architecture, I've employed the use of a union to rearrange the byte order to maintain the same overall functionality. These changes in both route (big-endian and little-endian) are based on the endian-ness of the CPU, which determines how numbers are stored in memory. 

Big-endian stores the most significant byte first, and little-endian stores the least significant byte first.
This change of behavior basically determines whether the resulting byte sequence will begin with the most significant byte (the traditional Bitcoin network byte order or "big-endian" layout) or the least significant byte (the inverse).