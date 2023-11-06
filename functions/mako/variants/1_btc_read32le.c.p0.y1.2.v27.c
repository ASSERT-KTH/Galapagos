uint32_t btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  return ((uint32_t) *(xp)           |
          (uint32_t) *(xp+1) << 8    |
          (uint32_t) *(xp+2) << 16   |
          (uint32_t) *(xp+3) << 24);
#else
  union {
    uint32_t ui;
    uint8_t arr[4];
  } num;
  num.arr[0] = xp[0];
  num.arr[1] = xp[1];
  num.arr[2] = xp[2];
  num.arr[3] = xp[3];
  return num.ui;
#endif
}