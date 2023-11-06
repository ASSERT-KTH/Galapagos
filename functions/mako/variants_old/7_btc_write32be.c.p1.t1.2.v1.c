Here's a variant of your C function, `btc_write32be(uint8_t *zp, uint32_t x)`, that achieves the same purpose without using an `#if` preprocessor directive or `memcpy()`. Instead, it uses bit manipulation which works correctly for both big endian and little endian systems.


void btc_write32be(uint8_t *zp, uint32_t x) {
    zp[0] = (uint8_t)(x >> 24) & 0xFF;
    zp[1] = (uint8_t)(x >> 16) & 0xFF;
    zp[2] = (uint8_t)(x >> 8) & 0xFF;
    zp[3] = (uint8_t)x & 0xFF;
}
