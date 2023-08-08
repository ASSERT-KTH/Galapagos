
#include <stdint.h>

uint32_t btc_read32le(const uint8_t *xp) 
{
#if defined(BTC_BIGENDIAN)
    union {
        uint32_t num;
        uint8_t bytes[4];
    } z;

    z.bytes[0] = xp[0];
    z.bytes[1] = xp[1];
    z.bytes[2] = xp[2];
    z.bytes[3] = xp[3];

  return (z.num);
#else
  uint32_t z;
  for(int n = 0; n < sizeof(z); n++)
  {
      z |= xp[n]<<8*n;
  }
  return z;
#endif
}

This variant accomplishes the same goal as the original function: interpreting array of bytes as a single 32 bits long unsigned int (considering endianness). The difference window lies in different approaches used: the first one applies bit-banging in the unionized type, using C Unions for endianness-agnostic implementation. The other one introduces a loop, and is designed to read arrays of any size, up to 32 bits where left shifting is done relative to the array index.