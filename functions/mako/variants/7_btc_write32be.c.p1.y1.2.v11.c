Version 1:

void btc_write32be(uint8_t *zp, uint32_t x) {
    if (sizeof(int) == 4) {
        zp[3] = (x & 0xff); 
        zp[2] = ((x >> 8) & 0xff);
        zp[1] = ((x >> 16) & 0xff);
        zp[0] = ((x >> 24) & 0xff);
    } 
    else {
        memcpy(zp, &x, sizeof(x));
    }
}


Version 2:

void btc_write32be(uint8_t *zp, uint32_t x) {
    if (sizeof(int) != 4) {
       memcpy(zp, &x, sizeof(x));
    } 
    else {
        uint32_t y = x;
        zp[0] = y >> 24;
        y <<= 8;
        zp[1] = y >> 24;
        y <<= 8;
        zp[2] = y >> 24;
        y <<= 8;
        zp[3] = y >> 24;
    }
}

Version 3:

void btc_write32be(uint8_t *zp, uint32_t x) {
#ifndef BTC_BIGENDIAN
  *(uint32_t*)zp = htonl(x);
#else
  zp[0] = x >> 24;
  zp[1] = x >> 16;
  zp[2] = x >>  8;
  zp[3] = x;
#endif
}

Please note that the check for the big-endianness of a machine is highly platform dependent and may need to be customized depending on the OS and compiler, usually by some sort of preprocessor directives or build system configurations.
Endianness tends to be better checked at compile-time, and handled with conditional compilation, as the original code provided does.