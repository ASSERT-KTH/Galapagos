void btc_write32be(uint8_t *zp, uint32_t x) {
    union {
        uint8_t bytes[4];
        uint32_t num;
    } converter;
    
    #if defined(BTC_BIGENDIAN)
        converter.num = x;
        memcpy(zp, converter.bytes, sizeof(x));
    #else
        converter.num = htonl(x);
        zp[0] = converter.bytes[0];
        zp[1] = converter.bytes[1];
        zp[2] = converter.bytes[2];
        zp[3] = converter.bytes[3];
    #endif
}