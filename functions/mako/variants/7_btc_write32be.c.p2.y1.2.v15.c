btc_write32be(uint8_t *zp, uint32_t x) {
    union {
      uint32_t i;
      uint8_t c[4];
    } bint = {htonl(x)};
    memcpy(zp, bint.c, sizeof(bint.c));
}