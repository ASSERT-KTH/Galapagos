
void btc_uint32_write(uint8_t *zp, uint32_t x) {
    #if defined(BTC_BIGENDIAN)
        for (int i = 0; i < 4; i++) {
            *zp = (x >> (i * 8));
            zp++;
        }
    #else
        uint32_t *zp_casted = (uint32_t*) zp;
        *zp_casted = x;
        zp += sizeof(x);
    #endif
}

In this version, logic remains similar but implementation varies a bit. 

For the `BTC_BIGENDIAN` case, a loop regulates the shift and increment operations avoiding repetition.

For the non-big endian case, instead of using `memcpy` function which requires a link to the `<string.h>` library, hence consuming more resources, the type of 'zp' is casted directly to `uint32_t` and the value `x` is assigned to the resulting pointer location, which should behave the same as `memcpy`. Then moves 'zp' forward within the allocated memory according to the size of 'x'. This will reduce resource usage, if apart from original function behavior also low-level optimization is part of changes needed, but will lose portability aspect.