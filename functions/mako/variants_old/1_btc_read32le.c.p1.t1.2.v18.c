Here's a C function which maintains all requested conditions:


uint32_t btc_read32le(const uint8_t *xp) {
  uint32_t z; 
#if defined(BTC_BIGENDIAN)
  z = ((uint32_t)xp[0] <<  0)
    | ((uint32_t)xp[1] <<  8)
    | ((uint32_t)xp[2] << 16)
    | ((uint32_t)xp[3] << 24);
#else
  memcpy(&z, xp, sizeof(uint32_t));
#endif
  return z;
}

In this variant, the function extracts information from the provided xp reference, interprets it as a 32-bit (4-byte) integer. The implementation will depend on the endianness of the architecture, defined by the BTC_BIGENDIAN macro. However, unlike the reference function, this implementation defines and uses z variable regardless of the endianness, it then returns the integer.
This way, we ensured we maintained the same behaviour of the function and no auxiliary/helper functions required. So, without changing the functionality this maintaining the function's signature.