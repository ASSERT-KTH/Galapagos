Variant 1:

void btc_write32be(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  *(uint32_t*)zp = x;
#else
  zp[0] = x >> 24 & 0xFF;
  zp[1] = x >> 16 & 0xFF;
  zp[2] = x >>  8 & 0xFF;
  zp[3] = x & 0xFF;
#endif
}


Variant 2:

void btc_write32be(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  uint32_t *xp = reinterpret_cast<uint32_t*>(zp);
  *xp = x;
#else
  for (int i = 3; i >= 0; i--) {
    zp[i] = x & 0xff;
    x >>= 8;
  }
#endif
}


Variant 3:

void btc_write32be(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  *((uint32_t*)zp) = x;
#else
  unsigned char *ptr = (unsigned char*) &x + 3;;
  for (int i = 0; i < 4; i++) {
    zp[i] = *ptr--;
  }
#endif
}


Variant 4:

void btc_write32be(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  *reinterpret_cast<uint32_t*>(zp) = x;
#else
  unsigned int byte_number = sizeof(uint32_t);
  for(int i=0; i<byte_number; i++) {
    zp[i] = x >> ((byte_number-1-i)*8) & 0xFF;
  }
#endif
}
