modp_norm(uint32_t x, uint32_t p) {
    return (int32_t)(x - (p & (((x - ((p + 1) >> 1)) >> 31) - 1)));
}