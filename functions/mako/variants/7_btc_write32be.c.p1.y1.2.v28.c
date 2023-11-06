1. Using Union and Bit fields:
The below code uses a combination of union and bit fields to accomplish the same functionality.


void btc_write32be(uint8_t *zp, uint32_t x) {
  union {
    uint32_t num;
    struct {
      uint8_t b0:8;
      uint8_t b1:8;
      uint8_t b2:8;
      uint8_t b3:8;
    } parts;
  } y;

#if defined(BTC_BIGENDIAN)
  memcpy(zp, &x, sizeof(x));
#else
  y.num = x;
  zp[0] = y.parts.b3;
  zp[1] = y.parts.b2;
  zp[2] = y.parts.b1;
  zp[3] = y.parts.b0;
#endif
}


2. Using Array and Pointer:

This version uses a single `uint32_t`