
void btc_write32be(uint8_t *zp, uint32_t x) {
    #if defined(BTC_BIGENDIAN)
        memcpy(zp, &x, sizeof(x));
    #else
        *((uint32_t *)zp) = __builtin_bswap32(x);
    #endif
}
