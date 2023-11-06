// Variant 1
void btc_write32be(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  for (size_t i = 0; i < sizeof(x); ++i) {
      zp[i] = ((uint8_t*)&x)[i];
  }
#else
  uint8_t *px = (uint8_t*)&x;
  zp[0] = px[3];
  zp[1] = px[2];
  zp[2] = px[1];
  zp[3] = px[0];
#endif
}

// Variant 2
void btc_write32be(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  zp[0] = *((uint8_t*)&x + 0);
  zp[1] = *((uint8_t*)&x + 1);
  zp[2] = *((uint8_t*)&x + 2);
  zp[3] = *((uint8_t*)&x + 3);
#else
  zp[0] = (x & 0xff000000) >> 24;
  zp[1] = (x & 0x00ff0000) >> 16;
  zp[2] = (x & 0x0000ff00) >> 8;
  zp[3] = (x & 0x000000ff);
#endif
}

// Variant 3
void btc_write32be(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  uint8_t* val_p = (uint8_t*)&x;
  zp[0] = val_p[0];
  zp[1] = val_p[1];
  zp[2] = val_p[2];
  zp[3] = val_p[3];
#else
  zp[0] = (uint8_t)(x / 16777216);
  zp[1] = (uint8_t)(x / 65536 % 256);
  zp[2] = (uint8_t)(x / 256 % 256);
  zp[3] = (uint8_t)(x % 256);
#endif
}