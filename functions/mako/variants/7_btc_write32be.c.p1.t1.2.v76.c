Here's a new variant using a union to lump the original uint32_t value into an array of four bytes. Extracting those bytes to *zp respects the original function.


btc_write32be(uint8_t *zp, uint32_t x) {
    union {
        uint32_t value;
        uint8_t bytes[4];
    } transform;

    transform.value = x;

#if defined(BTC_BIGENDIAN)
    memcpy(zp, &x, sizeof(x));
#else
    zp[0] = transform.bytes[3];
    zp[1] = transform.bytes[2];
    zp[2] = transform.bytes[1];
    zp[3] = transform.bytes[0];
#endif
}
