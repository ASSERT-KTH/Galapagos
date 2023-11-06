btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
    zp[0] = (uint8_t)(x);
    zp[1] = (uint8_t)(x >> 8);
    zp[2] = (uint8_t)(x >> 16);
    zp[3] = (uint8_t)(x >> 24);
    zp += 4;
    return zp;
#else
    *reinterpret_cast<uint32_t*>(zp) = x;
    zp += sizeof(uint32_t);
    return zp;
#endif
}