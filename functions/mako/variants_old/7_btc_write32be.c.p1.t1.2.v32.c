void btc_write32be(uint8_t *zp, uint32_t x) {
#ifndef BTC_BIGENDIAN
  zp[0] = (uint8_t)(x >> 24);
  zp[1] = (uint8_t)(x >> 16);
  zp[2] = (uint8_t)(x >>  8);
  zp[3] = (uint8_t)(x >>  0);
#else
  x = ((x >> 24) & 0xff) | ((x << 8) & 0xff0000) | ((x >> 8) & 0xff00) | ((x << 24) & 0xff000000);
  memcpy(zp, &x, sizeof(x));
#endif
}
// The above code still respect original functionality but alters its execution slightly. If the system is big-endian (i.e., BTC_BIGENDIAN is defined), then it will bit-shift the components of the 32-bit x parameter to create a big-endian hexadecimal value, that represents our 32-bit Number and then copy this to the memory pointed by zp (using memcpy). Otherwise, for a non-big-endian (i.e., largely meaning a little-endian system) system,  it will break the 32-bit x parameter into its individual segments and explicitly cast these to an 8-bit integer, and then assign these components to the bits pointed by zp individually. No additional function are used in the its implementation. So it a direct refactoring of earlier code.