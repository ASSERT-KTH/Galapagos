Here is a variant, the revised implementation uses bitwise operations and directly writes to the buffer based on whether the machine is a big-endian or a little-endian.


void btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  zp[0] = (x >> 24) & 0xFF;
  zp[1] = (x >> 16) & 0xFF;
  zp[2] = (x >> 8) & 0xFF;
  zp[3] = x & 0xFF;
#else
  zp[0] = x & 0xFF;
  zp[1] = (x >> 8) & 0xFF;
  zp[2] = (x >> 16) & 0xFF;
  zp[3] = (x >> 24) & 0xFF;
#endif
}

This version of the function directly uses array indexing instead of incrementing the pointer. Instead of relying on memcpy in the little-endian case, it breaks down x into bytes using bitwise AND and bitwise shift, similar to the big-endian case. Note that this variant is likely to work slower than the original version, although it arguably makes the logic more clear and ubiquitous across the two cases. The function returns void instead of pointer to keep things consistent as modifying zp does not imply the need to return it back. This makes sense assuming the caller of the function would have maintained tracking of zp.