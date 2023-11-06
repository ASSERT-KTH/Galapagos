The function `btc_read32le(const uint8_t *xp)` decodes from a bytearray `xp` of 4 `uint8_t`, a 32 bit little-endian integer. I keep the logic and change depending on the endianness:


btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
    uint32_t rsp = 0;
    rsp |= xp[0];
    rsp |= xp[1] << 8;
    rsp |= xp[2] << 16;
    rsp |= xp[3] << 24;
    return rsp;
#else
    uint32_t respond;
    for (uint8_t i = 0; i < sizeof(respond); i++)
        ((uint8_t*)&respond)[i] = xp[i];
    return respond;
#endif
}

For the bigendian conditions, I use `rsp` which does the byte promotions and shifts explicitly using shift (`<<`) and binary 'or' (`|`) operations as original code. For the little-endian, I loop the processing into the `uint32_t respond` to retain his functionality of original code. Remember to not use 'magic numbers', refering to the explicit 0, 8, 16 and 24, make your code more modular.