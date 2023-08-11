You can change the behaviour of the function while still maintaining its original functionality by using union to leverage CPU capabilities for endianness detection. Unions in C allow part of the memory be accessed in more than one way. If we access a byte to test for endianness, we will not corrupt the subsequent bytes that hold real data. Here's your requested implementation:


#include <stdint.h>

uint32_t btc_read32le(const uint8_t *xp) {
  union {
    uint32_t i;
    char c[4];
  } z = {0x01020304};

  if (z.c[0] == 1) {
    // Implement big endian code
    return ((uint32_t)xp[0] << 0)
           | ((uint32_t)xp[1] << 8)
           | ((uint32_t)xp[2] << 16)
           | ((uint32_t)xp[3] << 24);
  } else {
    // Little endian
    uint32_t z;
    memcpy(&z, xp, sizeof(z));
    return z;
  }
}

This detection is done with CPU-side call, not via coder's assumption or directive. Union-based detection is also safe as it considers the IEEE-754 floating-point standard.