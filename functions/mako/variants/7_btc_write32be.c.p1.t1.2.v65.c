Here's a different approach to the function which reverses the data bytes in place on little-endian systems with bitwise operations:


void btc_write32be(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  memcpy(zp, &x, sizeof(x));
#else
  x = ((x & 0xFF000000) >> 24) |
      ((x & 0x00FF0000) >>  8) |
      ((x & 0x0000FF00) <<  8) |
      ((x & 0x000000FF) << 24);
      
  memcpy(zp, &x, sizeof(x));
#endif
}


In this version, instead of writing each byte individually to the destination, we shift all of the bits in the `uint32_t` to their appropriate place. This is useful when memcpy is faster than writing individual bytes. The resulting integer representation remains the same; it's just stored byte-wise in backwards order, which effectivelly switches between little-endian and big-endian representations.