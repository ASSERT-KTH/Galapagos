The purpose of the function is to read 4 bytes from an array pointed to by "xp" and store it in the variable that "zp" is pointing to (if there are at least 4 bytes available), under either endian relativity. In this change, I do not use the "memcpy()" function, instead, I even write the LITTLE_ENDIAN part to build the integer explicitly. I then introduce a new manner of checking the size before advancing "xp" and "xn".


btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
    if (*xn < sizeof(uint32_t))
        return 0;
    
#if defined(BTC_BIGENDIAN)
    *zp = ((uint32_t)(*xp)[0] << 24)
        | ((uint32_t)(*xp)[1] << 16)
        | ((uint32_t)(*xp)[2] << 8)
        | ((uint32_t)(*xp)[3] << 0);
#else
    *zp = ((uint32_t)(*xp)[0] <<  0)
        | ((uint32_t)(*xp)[1] <<  8)
        | ((uint32_t)(*xp)[2] << 16)
        | ((uint32_t)(*xp)[3] << 24);
#endif

    if (*zn >= sizeof(uint32_t)) {
        *xp += 4;
        *xn -= 4;
    }

    return 1;
}
