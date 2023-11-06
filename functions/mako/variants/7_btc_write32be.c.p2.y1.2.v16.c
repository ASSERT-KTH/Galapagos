btc_write32be(uint8_t *zp, uint32_t x) {
  union {
    uint32_t u32;
    uint8_t u8[4];
  } u;

#if defined(BTC_BIGENDIAN)
  u.u32 = x;
  memcpy(zp, u.u8, sizeof(x));
#else
  u.u32 = (x >> 24) | (x >> 8) & 0x0000ff00 | (x << 8) & 0x00ff0000 | x << 24;
  memcpy(zp, u.u8, sizeof(u.u32));
#endif
}