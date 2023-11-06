uint32_t btc_read32le(const uint8_t *xp) {
#ifdef BTC_BIGENDIAN
    return ((uint32_t)xp[3])
         | ((uint32_t)xp[2] << 8)
         | ((uint32_t)xp[1] << 16)
         | ((uint32_t)xp[0] << 24);
#else
    union {
        uint32_t z;
        uint8_t data[4];
    } un;

    un.data[0] = xp[0];
    un.data[1] = xp[1];
    un.data[2] = xp[2];
    un.data[3] = xp[3];
    
    return un.z;
#endif
}