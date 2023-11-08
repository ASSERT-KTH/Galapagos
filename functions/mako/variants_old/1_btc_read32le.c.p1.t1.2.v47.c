uint32_t btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
    return ((uint32_t)xp[0]) 
       | ((uint32_t)xp[1] <<  8)
       | ((uint32_t)xp[2] << 16)
       | ((uint32_t)xp[3] << 24);
#else
    uint32_t z = 0;
    for (size_t i = 0; i < sizeof(z); ++i) 
    {
        z <<= 8; 
        z |= xp[i]; // mimicking the behaviour of memcpy
    }
    return z;
#endif
}