Here's an equivalent function that achieves the same result with the original function:


btc_write32be(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
    zp[0] = ((char *)&x)[0];
    zp[1] = ((char *)&x)[1];
    zp[2] = ((char *)&x)[2];
    zp[3] = ((char *)&x)[3];
#else
    zp[0] = x >> 24 & 0xff;
    zp[1] = x >> 16 & 0xff;
    zp[2] = x >> 8  & 0xff;
    zp[3] = x       & 0xff;
#endif
}
