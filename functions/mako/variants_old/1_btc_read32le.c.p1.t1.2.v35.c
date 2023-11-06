The following code swaps the endian groups during conversion based on a define flag, making use of bitwise operations:


btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  return ((uint32_t)xp[3] << 0)
       | ((uint32_t)xp[2] << 8)
       | ((uint32_t)xp[1] << 16)
       | ((uint32_t)xp[0] << 24);
#else
  uint32_t z;
  z = ((uint32_t)xp[3])
    | ((uint32_t)xp[2] << 8)
    | ((uint32_t)xp[1] << 16)
    | ((uint32_t)xp[0] << 24);
  return z;
#endif
}

This variant also reads 4 bytes into an unsigned 32-bit integer, but reverses the order of the bytes based on the BTC_BIGENDIAN flag.