
void btc_uint32_write(uint8_t *zp, uint32_t x) {
    union {
        uint32_t u32;
        uint8_t u8[4];
    } convert;

#if defined(BTC_BIGENDIAN)
    convert.u32 = x;
    *zp++ = convert.u8[3];
    *zp++ = convert.u8[2];
    *zp++ = convert.u8[1];
    *zp = convert.u8[0];
#else
    convert.u32 = x;
    memcpy(zp, convert.u8, sizeof(x));
#endif
}
