
#include <stdint.h>
#include <string.h>

uint8_t* btc_uint32_write(uint8_t *zp, uint32_t x) {
#ifdef BTC_BIGENDIAN
  *zp++ = (uint8_t)(x >> 24) & 0x000000ff;
  *zp++ = (uint8_t)(x >> 16) & 0x000000ff;
  *zp++ = (uint8_t)(x >>  8) & 0x000000ff;
  *zp++ = (uint8_t)(x >>  0) & 0x000000ff;
  return zp;
#else
  uint8_t *xp = (uint8_t*)&x;
  *zp++ = *xp++;
  *zp++ = *xp++;
  *zp++ = *xp++;
  *zp++ = *xp++;
  return zp;
#endif
}

This version of the function variant behaves the same compared to the original code. However, the implementation is slightly changed with manual copy in the non-big-endian case for visibility and masking in the big-endian case for safety. It operates with not presuming in place operation safety for memcpy calls, it copy bytes from unsigned 32 integer to target byte array one-by-one as specified order directly.