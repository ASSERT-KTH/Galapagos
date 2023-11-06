Here is the program variant:


uint32_t btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  return ((uint32_t)xp[3] << 0)
       | ((uint32_t)xp[2] << 8)
       | ((uint32_t)xp[1] << 16)
       | ((uint32_t)xp[0] << 24);
#else
  return xp[0]
       | (xp[1] << 8)
       | (xp[2] << 16)
       | (xp[3] << 24);
#endif
}


This version of the function does essentially the same thing as the original, i.e., it reads a little-endian integer from memory. However, it computes the integer slightly differently. The macro BTC_BIGENDIAN is checked to determine the byte order of the host machine. This version of the function doesn't rely on memcpy operation for non-big-endian systems, but directly shifts the individual byte value and does bitwise OR to compose the final integer. For big-endian system, order of byte positioning in shifts is reversed.