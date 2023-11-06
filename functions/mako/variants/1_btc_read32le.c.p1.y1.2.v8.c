1.

// Use an union subtype for type conversion.
uint32_t btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
    return ((uint32_t)xp[0] <<  0)
         | ((uint32_t)xp[1] <<  8)
         | ((uint32_t)xp[2] << 16)
         | ((uint32_t)xp[3] << 24);
#else
    union { uint32_t u32; uint8_t u8[4]; } z;
    for (int i = 0 ; i < 4 ; i++)
        z.u8[i] = xp[i];
    return z.u32;
#endif
}


2.

// Reverse the shift order for big endian systems. Little endian system's implementation is unaffected.
uint32_t btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
    return ((uint32_t)xp[3] <<  0)
         | ((uint32_t)xp[2] <<  8)
         | ((uint32_t)xp[1] << 16)
         | ((uint32_t)xp[0] << 24);
#else
    uint32_t z;
    memcpy(&z, xp, sizeof(z));
    return z;
#endif
}


3.

// Return std::bit_cast<uint32_t>(xp[0]); if using C++20.
uint32_t btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
    return ((uint32_t)xp[0] <<  0)
         | ((uint32_t)xp[1] <<  8)
         | ((uint32_t)xp[2] << 16)
         | ((uint32_t)xp[3] << 24);
#else
    uint32_t z;
    z = xp[0] | xp[1] << 8 | xp[2] << 16 | xp[3] << 24;
    return z;
#endif
}
