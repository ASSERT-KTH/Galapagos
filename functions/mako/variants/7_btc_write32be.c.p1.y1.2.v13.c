1)


void btc_write32be_1(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  memcpy(zp, &x, sizeof(x));
#else
  *zp++ = (uint8_t) (x >> 24);
  *zp++ = (uint8_t) (x >> 16);
  *zp++ = (uint8_t) (x >>  8);
  *zp = (uint8_t) (x >>  0);
#endif
}


2)


void btc_write32be_2(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  uint8_t* pByte = (uint8_t*)&x;
  zp[0] = pByte[0];
  zp[1] = pByte[1];
  zp[2] = pByte[2];
  zp[3] = pByte[3];
#else
  zp[0] = x >> 24;
  zp[1] = (x & 0x00FF0000) >> 16;
  zp[2] = (x & 0x0000FF00) >> 8;
  zp[3] = (x & 0x000000FF);
#endif
}


3)
  

void btc_write32be_3(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  zp[0] = ((uint8_t*)(&x))[0];
  zp[1] = ((uint8_t*)(&x))[1];
  zp[2] = ((uint8_t*)(&x))[2];
  zp[3] = ((uint8_t*)(&x))[3];
#else
  zp[0] = (uint8_t)(x / (1 << 24));
  zp[1] = (uint8_t)((x % (1 << 24)) / (1 << 16));
  zp[2] = (uint8_t)((x % (1 << 16)) / (1 << 8));
  zp[3] = (uint8_t)(x % (1 << 8));
#endif
}
