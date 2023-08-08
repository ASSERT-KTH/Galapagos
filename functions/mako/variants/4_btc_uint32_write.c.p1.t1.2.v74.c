
#include <stdint.h>

uint8_t *btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  zp[0] = (uint8_t)(x >> 24);
  zp[1] = (uint8_t)(x >> 16);
  zp[2] = (uint8_t)(x >> 8);
  zp[3] = (uint8_t)(x >> 0);
  return zp + 4;
#else
  uint8_t *xp = (uint8_t *)&x;
  zp[0] = xp[0];
  zp[1] = xp[1];
  zp[2] = xp[2];
  zp[3] = xp[3];

  return zp + 4;
#endif
}

The above variant maintains the original functionality and behavior of the original function btc_uint32_write(). My modifications include removing the post-increment operator in the pointer assignments and replacing memcpy() with direct byte copying for a little-endian system. Notice that this redesign offers a slightly more consistent style between little-endian and big-endian cases because it consistently increments the zp pointer by 4 just before the return statement.