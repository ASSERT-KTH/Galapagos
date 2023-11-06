Here's a variant of your function that preserves the original functionality:

#include <stdint.h>

int btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  uint32_t temp = 0;

  if (*xn < 4)
    return 0;

#if defined(BTC_BIGENDIAN)
  for(int idx = 0; idx < 4; ++idx) {
    temp = temp | ((*xp)[idx] << (8 * idx));
  }
  *zp = temp;
#else
  temp = ((*xp)[3] << 24) 
       | ((*xp)[2] << 16)
       | ((*xp)[1] <<  8)
       | (*xp)[0];
  *zp = temp;
#endif

  *xp += 4;
  *xn -= 4;

  return 1;
}

This modifies the function in two primary ways. For big-endian systems, it packs the bytes into your `uint32_t` in a loop in ascending order, shifting the bytes increasingly larger amounts rather than hard coding it. For little-endian systems, it retrieves bytes by explicit offsets rather than use memcpy. 

Of course, these two ways have the same results as your original function. Note that that claimed maintainability, of course, assumes that the code uses 8 bits per byte and `BTC_BIGENDIAN` meets your needs for determining endian-ness.