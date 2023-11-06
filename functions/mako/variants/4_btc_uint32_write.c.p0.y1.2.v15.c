void btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
    for (int i = 0; i < 4; i++)
    {
        *zp++ = x >> (8 * i);
    }
    return zp;
#else
    *(uint32_t *)zp = x;
    return zp + sizeof(uint32_t);
#endif
}