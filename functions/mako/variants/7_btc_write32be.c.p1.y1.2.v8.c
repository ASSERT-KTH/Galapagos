1. Variant using logical and (&) operator:


void btc_write32be(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  memcpy(zp, &x, sizeof(x));
#else
  zp[0] = (x & 0xFF000000) >> 24;
  zp[1] = (x & 0x00FF0000) >> 16;
  zp[2] = (x & 0x0000FF00) >>  8;
  zp[3] = (x & 0x000000FF) >>  0;
#endif
}


2. Variant using for loop:


void btc_write32be(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
    memcpy(zp, &x, sizeof(x));
#else
    for(int i = 0; i < 4; ++i) {
        zp[i] = (x >> ((3 - i)*8);
    }
#endif
}
     

3. Variant using union


void btc_write32be(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  memcpy(zp, &x, sizeof(x));
#else
  union {
    uint8_t b[4];
    uint32_t x;
  } u;
  u.x = x;
  for (int i = 0; i < 4; ++i) {
    zp[i] = u.b[3 - i];
  }
#endif
}


4. Variant using bitwise operations with single digit values:
    

void btc_write32be(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  memcpy(zp, &x, sizeof(x));
#else
  zp[0] = x / 16777216; // 2^24
  zp[1] = (x % 16777216) / 65536; // 2^16
  zp[2] = (x % 65536) / 256; // 2^8
  zp[3] = x % 256; //2^0
#endif
}
