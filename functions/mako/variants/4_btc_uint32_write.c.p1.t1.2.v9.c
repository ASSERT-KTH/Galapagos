
void btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
    zp[0] = (uint8_t)(x >>  0);
    zp[1] = (uint8_t)(x >>  8);
    zp[2] = (uint8_t)(x >> 16);
    zp[3] = (uint8_t)(x >> 24);
#else
    zp[0] = (uint8_t)x;
    zp[1] = (uint8_t)(x >> 8);
    zp[2] = (uint8_t)(x >> 16);
    zp[3] = (uint8_t)(x >> 24);
#endif
}

This version of the function does not return a value but it still writes the uint32 to the given buffer in the correct endian order. If a return is absolutely required, use cast to return input argument `zp`. Although additional cast mentioned may violate good C programming practice when the function returns different type than originally declared, ignoring this fact will look as follows:


uint8_t* btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
    zp[0] = (uint8_t)(x >>  0);
    zp[1] = (uint8_t)(x >>  8);
    zp[2] = (uint8_t)(x >> 16);
    zp[3] = (uint8_t)(x >> 24);
#else
    zp[0] = (uint8_t)x;
    zp[1] = (uint8_t)(x >> 8);
    zp[2] = (uint8_t)(x >> 16);
    zp[3] = (uint8_t)(x >> 24);
#endif
    return zp;
}
