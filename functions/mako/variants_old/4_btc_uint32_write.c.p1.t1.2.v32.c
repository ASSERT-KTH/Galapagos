
btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  *zp++ = (uint8_t)((x >> 24) & 0xFF);
  *zp++ = (uint8_t)((x >> 16) & 0xFF);
  *zp++ = (uint8_t)((x >>  8) & 0xFF);
  *zp++ = (uint8_t)(x & 0xFF);
  return zp;
#else
  zp[0] = x & 0xFF;
  zp[1] = (x >> 8) & 0xFF;
  zp[2] = (x >> 16) & 0xFF;
  zp[3] = (x >> 24) & 0xFF;
  return zp + 4;
#endif
}

Here's the C code that changes the original behavior but still maintains the original functionality. The same endianness is maintained; big endian is manually written by bit-shifting and using bitwise and operation (AND) to retrieve the respective byte. For the little-endian, individual bytes from the integer "x" are written one by one using a similar method. This variation doesn't use memcpy unlike in the original C function. Instead, bytes are manually computed using few bit operations and directly written to memory.