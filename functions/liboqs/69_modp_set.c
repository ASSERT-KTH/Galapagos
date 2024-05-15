modp_set(int32_t x, uint32_t p) {
    uint32_t w;

    w = (uint32_t)x;
    w += p & -(w >> 31);
    return w;
}