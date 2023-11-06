Here is a variant of the original function which uses union for both big-endian and little-endian systems. It preserves the same functionality.


void btc_write32be(uint8_t *zp, uint32_t x) {
  union {
    uint32_t u32;
    uint8_t u8[4];
  } u;

#if defined(BTC_BIGENDIAN)
  u.u32 = x;
  memcpy(zp, u.u8, sizeof(u.u32));
#else
  u.u32 = x;
  zp[0] = u.u8[3];
  zp[1] = u.u8[2];
  zp[2] = u.u8[1];
  zp[3] = u.u8[0];
#endif
}

The union allows us to view the same memory area as both a 32-bit unsigned integer and an array of four 8-bit unsigned integers. Hence, for a big-endian system, we put x into the union as a 32-bit unsigned integer and then copy the corresponding bytes. For a little-endian system, we also put x into the union as a 32-bit unsigned integer, but then we manually shuffle bytes into the target array.