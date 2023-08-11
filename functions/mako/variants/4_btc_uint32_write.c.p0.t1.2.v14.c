btc_uint32_write(uint8_t *zp, uint32_t x){
#if defined(BTC_BIGENDIAN)
    *zp++ = (x & 0xff);
    x >>= 8;
    *zp++ = (x & 0xff);
    x >>= 8;
    *zp++ = (x & 0xff);
    x >>= 8;
    *zp++ = (x & 0xff);
    return zp;
#else
    for(size_t i = 0; i < sizeof(x); ++i, ++zp) {
        *zp = (uint8_t) (x >> (i * 8));
    }
    return zp;
#endif
}