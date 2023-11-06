uint32_t btc_read32le(const uint8_t *xp) {
    uint32_t z = 0;
#ifdef BTC_BIGENDIAN
    for(int i = 0; i< 4; i++)
    {
        z |= ((uint32_t)xp[i]) << (i*8);
    }
#else
    z = *((uint32_t*)xp);
#endif
    return z;
}