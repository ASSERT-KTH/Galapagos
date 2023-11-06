uint32_t btc_read32le(const uint8_t *xp) {

#ifdef BTC_BIGENDIAN
    return (uint32_t)((xp[3] << 24) | (xp[2] << 16) | (xp[1] << 8) | xp[0]);
#else
    uint32_t z;
    z = xp[0] | xp[1] << 8 | xp[2] << 16 | xp[3] << 24;
    return z;
#endif
}