Variant 1:


void btc_write32be(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  *(uint32_t*)zp = x;
#else
  zp[0] = (x & 0xFF000000) >> 24;
  zp[1] = (x & 0x00FF0000) >> 16;
  zp[2] = (x & 0x0000FF00) >> 8;
  zp[3] = (x & 0x000000FF);
#endif
}

Notice, that applying the masking operation allows to concentrate exclusively on the bits that we are interested in while shifting right.

Variant 2:


void btc_write32be(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  *(uint32_t *)zp = x;
#else
  for (int i = 0; i < 4; i++)
    zp[i] = (x >> (24 - 8 * i));
#endif
}

This version of the function changes nothing semantically, but instead of writing each line of the little endian shift manually, it uses a loop unrolling to make your code more DRY (Do not Repeat Yourself).

Variant 3:


void btc_write32be(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
    zp[0] = ((x)&0xff), zp[1] = ((x >> 8) & 0xff), zp[2] = ((x >> 16) & 0xff), zp[3] = ((x >> 24) & 0xff);
#else
    zp[0] = (x & 0xff000000) >> 24;
    zp[1] = (x & 0x00ff0000) >> 16;
    zp[2] = (x & 0x0000ff00) >> 8;
    zp[3] = (x & 0x000000ff);
#endif
}


Variant 4:


void btc_write32be(uint8_t *zp, uint32_t x) {
  union {
    uint8_t bytes[4];
    uint32_t word;
  } tmp;
  tmp.word = x;
#if defined(BTC_BIGENDIAN)
  memcpy(zp, tmp.bytes, sizeof(tmp.bytes));
#else
  for(int i = 0; i < 4; i++)
    zp[i] = tmp.bytes[3 - i];
#endif
}

A union was used here to simultaneous represent bytes and integer. This solution doesn't use explicit masking or shifting.