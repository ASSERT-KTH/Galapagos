The function `btc_read32le` reads a 32-bit integer (4 bytes) from a memory location, `xp`. The data is read in little-endian format, i.e., the least significant byte is at the smallest address. 

If the processor supporting the C environment/BTC_BIGENDIAN macro is set, it indicates that the processor byte order is big-endian. Huge endian is the format than bytes with heavier priorityare placed at smaller memory addresses. Under these conditions, the order of byte loading should be reversed.

Let's create the same function achieving the original functionality but modifies some internals:


uint32_t btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  uint32_t result = 0u;
  int i;
  for(i = 0; i < 4; i++) {
    result |= ((uint32_t)xp[i] << (24 - (8 * i)));
  }
  return result;
#else
  union {
    uint32_t val;
    uint8_t byte[4];
  } u;
  u.byte[0] = xp[0];
  u.byte[1] = xp[1];
  u.byte[2] = xp[2];
  u.byte[3] = xp[3];
  return u.val;
#endif
}

This variant of the function uses a union on little-endian systems for loading bytes, which is an alternative way to memcpy. For big-endian systems, it uses a loop to shift bytes, which might be considered a more readable style.