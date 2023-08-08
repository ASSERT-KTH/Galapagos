
void btc_uint32_write(uint8_t *zp, uint32_t x) {
    #if defined(BTC_BIGENDIAN)
        *zp++ = (x & 0xff000000) >> 24;
        *zp++ = (x & 0x00ff0000) >> 16;
        *zp++ = (x & 0x0000ff00) >>  8;
        *zp++ = (x & 0x000000ff);
    #else
        zp[0] = x & 0x000000ff;
        zp[1] = (x & 0x0000ff00) >>  8;
        zp[2] = (x & 0x00ff0000) >> 16; 
        zp[3] = (x & 0xff000000) >> 24;
    #endif
}

In the modified version, the program will deliver the same outcome even though I've slightly tinkered with the shift logic and binary AND operations.
NB: The downside here is that for the little endian portion, you're segregating into each `zp[ ]` section as opposed to utilizing `memcpy`. This could be marginally slower, but it sustains functionality.