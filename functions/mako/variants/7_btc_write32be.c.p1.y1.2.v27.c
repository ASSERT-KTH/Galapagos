Variant 1:

void btc_write32be(uint8_t* zp, uint32_t x) {
    #if defined(BTC_BIGENDIAN)
      memmove(zp, &x, sizeof(x));
    #else
      zp[3] = x & 0xff;
      zp[2] = (x >> 8) & 0xff;
      zp[1] = (x >> 16) & 0xff;
      zp[0] = (x >> 24) & 0xff;
    #endif
}

Variant 2:

void btc_write32be(uint8_t *zp, uint32_t x) {
  #if defined(BTC_BIGENDIAN)
    uint8_t *xp = (uint8_t*)&x;
    zp[0] = xp[3];
    zp[1] = xp[2];
    zp[2] = xp[1];
    zp[3] = xp[0];
  #else
    zp[0] = (uint8_t) (x >> 24);
    zp[1] = (uint8_t) (x >> 16);
    zp[2] = (uint8_t) (x >> 8);
    zp[3] = (uint8_t) (x);
  #endif
}

Variant 3:

void btc_write32be(uint8_t* zp, uint32_t x) {
    #if defined(BTC_BIGENDIAN)
      zp[0] = ((char*)&x)[0];
      zp[1] = ((char*)&x)[1];
      zp[2] = ((char*)&x)[2];
      zp[3] = ((char*)&x)[3];
    #else
      zp[0] = x / 16777216; 
      zp[1] = x / 65536 % 256; 
      zp[2] = x / 256 % 256; 
      zp[3] = x % 256; 
    #endif
}
