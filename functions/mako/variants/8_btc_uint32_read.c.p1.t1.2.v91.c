The following code modifies approach taken in the original function while preserving the same set of rules:

#include <stdint.h>
#include <string.h>

btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn < 4)
    return 0;

#if defined(BTC_BIGENDIAN)
  *zp = (*(*xp)) | (*(*xp+1))<<8 | (*(*xp+2))<<16 | (*(*xp+3))<<24;
#else
  *zp = **(uint32_t**)xp;
#endif

  *xp += 4;
  *xn -= 4;

  return 1;
}


The change here keeps the functionality intact, using explicit pointer dereferencing instead of array subscript in row 7-8, and explicit casting in row 10, for systems which are not endian-oriented. 
However, one should not overlook addressing safety features built in to using `memcpy()`, as this approach is potentially hazardous with unculled pointer resource.