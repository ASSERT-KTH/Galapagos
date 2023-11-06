
uint32_t btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  return ((uint32_t)xp[3] <<  0)
       | ((uint32_t)xp[2] <<  8)
       | ((uint32_t)xp[1] << 16)
       | ((uint32_t)xp[0] << 24);
#else
  return xp[0] | (xp[1] << 8) | (xp[2] << 16) | (xp[3] << 24);
#endif
}
 

In the revised code, we absorb the memcpy operation into the return statement to perform the bit shifting for little-endian systems. On big-endian systems, this revised code now reads the bytes in reverse order, which correctly reads the bytes as a little-endian integer.