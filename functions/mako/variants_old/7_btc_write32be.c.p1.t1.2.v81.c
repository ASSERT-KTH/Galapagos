void btc_write32be(uint8_t *zp, uint32_t x) {
    union {
        uint32_t u32;
        uint8_t u8[4];
    } conv = { .u32=x };

#if defined(BTC_BIGENDIAN)
    zp[0] = conv.u8[0];
    zp[1] = conv.u8[1];
    zp[2] = conv.u8[2];
    zp[3] = conv.u8[3];
#else
    zp[0] = conv.u8[3];
    zp[1] = conv.u8[2];
    zp[2] = conv.u8[1];
    zp[3] = conv.u8[0];
#endif
}