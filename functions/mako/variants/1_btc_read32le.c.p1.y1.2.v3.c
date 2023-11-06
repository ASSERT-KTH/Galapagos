1)

uint32_t btc_read32le(const uint8_t *xp) {
#ifdef BTC_BIGENDIAN
    return ((uint32_t)xp[3] << 0)
         | ((uint32_t)xp[2] << 8)
         | ((uint32_t)xp[1] << 16)
         | ((uint32_t)xp[0] << 24);
#else
    return *(const uint32_t*) xp;
#endif
}


2)

uint32_t btc_read32le(const uint8_t *xp) {
#ifdef BTC_BIGENDIAN
    uint32_t r = 0;
    int i;
    for(i=0; i<4; i++)
      r |= xp[i] << (24 - i*8);
    return r;
#else
    uint32_t z;
    memcpy(&z, xp, sizeof(uint32_t));
    return z;
#endif 
}


3)

uint32_t btc_read32le(const uint8_t *xp) {
#ifdef BTC_BIGENDIAN
    return BitConverter.ToUInt32(xp, 0);
#else
    return cp[3] + (cp[2] << 8) + (cp[1] << 16) + (cp[0] << 24);
#endif
}



4)

uint32_t btc_read32le(const uint8_t *xp) {
#ifdef BTC_BIGENDIAN
    return static_cast<uint32_t>(xp[0])
         | static_cast<uint32_t>(xp[1] << 8)
         | static_cast<uint32_t>(xp[2] << 16)
         | static_cast<uint32_t>(xp[3] << 24);
#else
    uint32_t z = 0;
    char *p = reinterpret_cast<char *>(z);
    memcpy(p, &xp, sizeof(p));
    return z;
#endif
}
