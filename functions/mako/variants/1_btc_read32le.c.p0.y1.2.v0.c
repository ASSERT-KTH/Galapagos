uint32_t btc_read32le(const uint8_t *xp) {
    #if defined(BTC_BIGENDIAN)
        return xp[0]
            | xp[1] << 8
            | xp[2] << 16
            | xp[3] << 24;
    #else
        uint32_t z = 0;
        for(int i = 0; i < sizeof(z); i++)
            z |= ((uint32_t)xp[i]) << (8 * i);
        return z;
    #endif
}