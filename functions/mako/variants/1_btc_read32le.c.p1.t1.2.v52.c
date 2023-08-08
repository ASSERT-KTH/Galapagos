Here is a variant of the function; it assigns the value of each byte in the array *xp to an unsigned 32-bit int, instead of using the memcpy (assuming little-endian) or bitwise-shift in BTC_BIGENDIAN side. 


btc_read32le(const uint8_t *xp) {
  uint32_t z = 0;
#if defined(BTC_BIGENDIAN)
  z = (z | xp[0]) << 8;
  z = (z | xp[1]) << 8;
  z = (z | xp[2]) << 8;
  z |= xp[3];
#else
  z |= (uint32_t)xp[0];
  z |= (uint32_t)xp[1] << 7;
  z |= (uint32_t)xp[2] << 14;
  z |= (uint32_t)xp[3] << 21;
#endif
  return z;
}

This behaves same as the original function but essentially uses no bitwise shifts for little-endian and no memcpy. The multiplicative factors and the bitwise OR operation handle the endianness inside the read action.