void btc_write32be(uint8_t *zp, uint32_t x) {
  union {
    uint32_t u32;
    uint8_t arr[4];
  } data;

#if defined(BTC_BIGENDIAN)
  data.u32 = x;
  memcpy(zp, &data, sizeof(x));
#else
  data.u32 = x;
  zp[0] = data.arr[3];
  zp[1] = data.arr[2];
  zp[2] = data.arr[1];
  zp[3] = data.arr[0];
#endif
}