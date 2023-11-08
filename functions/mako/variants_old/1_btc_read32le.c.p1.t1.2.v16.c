#include <stdint.h>

uint32_t btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  uint32_t z =
    ((uint32_t)xp[0])
  | ((uint32_t)xp[1] << 8)
  | ((uint32_t)xp[2] << 16)
  | ((uint32_t)xp[3] << 24);
  return z;
#else
  return *(uint32_t*)xp;
#endif
}