Here is a modified version of your code:


#include <stdint.h>

uint8_t *btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
    zp[3] = (x >>  0) & 0xff;
    zp[2] = (x >>  8) & 0xff;
    zp[1] = (x >> 16) & 0xff;
    zp[0] = (x >> 24) & 0xff;
#else
    zp[0] = (x >>  0) & 0xff;
    zp[1] = (x >>  8) & 0xff;
    zp[2] = (x >> 16) & 0xff;
    zp[3] = (x >> 24) & 0xff;
#endif
	return zp + 4;
}

This version of the function avoids moving the pointer and therefore avoids potentially undefined behavior. It also maintains the function's original functionality by writing the same values in the original memory order, and then increments and returns the original pointer to ensure native endianness alignment.
Another change compared to the original function is "& 0xff" - to restrict the number to a byte as function manipulates the last 2 digits of the hex number (i.e. byte by byte) in order to shape the data into correct endianness which ensures that there isn’t inadvertently extraneous data remaining on the leading digits when storing to the byte sized uint8_t.