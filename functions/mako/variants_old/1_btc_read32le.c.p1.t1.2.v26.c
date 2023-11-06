Sure, a equivalent alternative of the provided C function could be code using `union` to achieve the same result:
Actually, you could change the implementation to use a union and a trick of memory placement of variables to produce similar behavior under both little and big-endian systems.


uint32_t btc_read32le(const uint8_t *xp) {
  union {
    uint8_t bytes[4];
    uint32_t integer;
  } endianUnion;

#if defined(BTC_BIGENDIAN)
  endianUnion.bytes[0] = xp[3];
  endianUnion.bytes[1] = xp[2];
  endianUnion.bytes[2] = xp[1];
  endianUnion.bytes[3] = xp[0];
#else
  memcpy(endianUnion.bytes, xp, sizeof(endianUnion.bytes));
#endif

  return endianUnion.integer;
}

Here, I use a union to hold the bytes, and use the underlying memory placement of the data within the union to copy and re-align the bytes in-case the system is big-endian.