Variant 1:


btc_write32be(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
    zp[0] = (x >> 24) & 0xFF;
    zp[1] = (x >> 16) & 0xFF;
    zp[2] = (x >> 8) & 0xFF;
    zp[3] = (x >> 0) & 0xFF;
#else
    zp[0] = x >> 24;
    zp[1] = x >> 16;
    zp[2] = x >> 8;
    zp[3] = x; // bitwise right shift operator by '0' can be ignored
#endif
}


Variant 2:


btc_write32be(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
    uint8_t* xp = (uint8_t*)&x;
    zp[0] = xp[3];
    zp[1] = xp[2];
    zp[2] = xp[1];
    zp[3] = xp[0];
#else
    zp[0] = (x >> 24);
    zp[1] = (x >> 16);
    zp[2] = (x >>  8);
    zp[3] = (x >>  0);
#endif
}



Variant 3:
  

btc_write32be(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
    for (int i = 0; i < sizeof(x); i++) {
        zp[i] = ((x >> ((3 - i) * 8)));
    }
#else
    zp[0] = (x >> 24);
    zp[1] = (x >> 16);
    zp[2] = (x >> 8);
    zp[3] = (x);
#endif
}
