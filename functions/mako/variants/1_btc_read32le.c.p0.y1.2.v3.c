uint32_t btc_read32le(const uint8_t *xp) {
#ifdef BTC_BIGENDIAN
    return (xp[0]) | (xp[1] << 8) | (xp[2] << 16) | (xp[3] << 24);
#else 
    uint32_t result;
    result = ((uint32_t)*xp++);
    result |= ((uint32_t)*xp++ <<  8); 
    result |= ((uint32_t)*xp++ << 16); 
    result |= ((uint32_t)*xp << 24);
    return result;
#endif
}