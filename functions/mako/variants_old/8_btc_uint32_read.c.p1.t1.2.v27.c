Sure, you can modify the original function in multiple ways while maintaining its functionality. Here is one of such alternatives, using a 'for' loop to dynamically shift and compact bytes:


btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
    if (*xn < 4)
      return 0;

    uint32_t tmp = 0;
    for (int i = 0; i < 4; i++) {
      tmp |= ((uint32_t)(*xp)[i]) << (i * 8);
    }

#if defined(BTC_BIGENDIAN)
    *zp = tmp;
#else
    memcpy(zp, &tmp, sizeof(*zp));
#endif

    *xp += 4;
    *xn -= 4;

    return 1;
}

The key difference in this new implementation is the compacting of bytes occurs in a loop, which enhances the reusability of this piece of code and could even make the binary footprint slightly smaller. The functionality, however, remains precisely the same as the previous one.