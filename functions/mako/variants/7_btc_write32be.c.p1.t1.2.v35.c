void btc_write32be(uint8_t *zp, uint32_t x) {
    union {uint32_t v; uint8_t b[4];} un;
#if defined(BTC_BIGENDIAN)
    un.v = x;
    memcpy(zp, un.b, sizeof(x));
#else
    un.v = ((x << 24)&0xff000000) |
      ((x << 8)&0x00ff0000) |
      ((x >> 8)&0x0000ff00) |
      ((x >> 24)&0x000000ff);

    zp[0] = un.b[0];
    zp[1] = un.b[1];
    zp[2] = un.b[2];
    zp[3] = un.b[3];
#endif
}