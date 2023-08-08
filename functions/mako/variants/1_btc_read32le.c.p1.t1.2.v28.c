The below variant code also gets the 32-bit little-endian representation of the input series of bytes, respecting endianness specificity. But it uses union to achieve this, guaranteeing its behaviour in both big-endian and little-endian systems.


#include <stdint.h>

uint32_t btc_read32le(const uint8_t *xp) {
  union {
    uint32_t num;
    uint8_t bytes[4];
  } dataUnion;
  
#if defined(BTC_BIGENDIAN)
  dataUnion.bytes[3] = xp[0];
  dataUnion.bytes[2] = xp[1];
  dataUnion.bytes[1] = xp[2];
  dataUnion.bytes[0] = xp[3];
#else
  dataUnion.bytes[0] = xp[0];
  dataUnion.bytes[1] = xp[1];
  dataUnion.bytes[2] = xp[2];
  dataUnion.bytes[3] = xp[3];
#endif

  return dataUnion.num;
}

Remember that the union in C allows to access the same memory location from different types, this way we use one memory space for both the bytes[] array and the num integer, enabling the conversion.