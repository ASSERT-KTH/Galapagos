btc_write32be(uint8_t *zp, uint32_t x) {
  union {
      uint32_t u32;
      uint8_t u8[4];
  } data;
  data.u32 = x;
#if defined(BTC_BIGENDIAN)
  memcpy(zp, &data.u32, sizeof(data.u32));
#else
  zp[0] = data.u8[3];
  zp[1] = data.u8[2];
  zp[2] = data.u8[1];
  zp[3] = data.u8[0];
#endif
}