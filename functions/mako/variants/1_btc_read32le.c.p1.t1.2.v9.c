uint32_t btc_read32le(const uint8_t *xp) {
#ifdef BTC_BIGENDIAN
    return ((uint32_t)xp[3] << 0)  
         | ((uint32_t)xp[2] << 8)
         | ((uint32_t)xp[1] << 16)
         | ((uint32_t)xp[0] << 24);
#else
    return ((uint32_t)xp[0])
         | ((uint32_t)xp[1] << 8)
         | ((uint32_t)xp[2] << 16)
         | ((uint32_t)xp[3] << 24);
#endif
}