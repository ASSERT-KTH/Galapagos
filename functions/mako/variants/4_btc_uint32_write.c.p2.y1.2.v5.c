btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
    int shift_bytes = 0;
    for(int i = 0; i < 4; i++, shift_bytes += 8){
        *zp++ = (x >> shift_bytes);
    }
#else
    uint32_t *xp = (uint32_t*)zp;
    *xp = x;
    zp += 4;
#endif
    return zp;
}