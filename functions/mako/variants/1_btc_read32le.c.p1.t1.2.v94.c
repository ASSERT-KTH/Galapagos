Sure, 
Here is another version maintaining the original functionality of the `btc_read32le` function:


uint32_t btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
    uint32_t z = 0;
    for(int i=0; i < 4; i++)
        z |= ((uint32_t)xp[i] << (i * 8));
    return z;
#else
    uint32_t z;
    for(int i=0; i < sizeof(uint32_t); i++)
        ((uint8_t*)&z)[i] = xp[i];
    return z;
#endif
}

In `BTC_BIGENDIAN` mode, we are manually doing the bit shifting within a loop rather than separately for each xp[i]. It aids readability a bit and reduces duplicative code. On the `else` part, we're directly copying memory byte by byte; we are avoiding usage of `memcpy`, providing more explicit control over bytes operation.