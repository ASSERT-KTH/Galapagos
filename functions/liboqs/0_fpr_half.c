static inline uint_64 fpr_half(uint_64 x) {
    /*
     * To divide a value by 2, we just have to subtract 1 from its
     * exponent, but we have to take care of zero.
     */
    uint32_t t;

    x -= (uint64_t)1 << 52;
    t = (((uint32_t)(x >> 52) & 0x7FF) + 1) >> 11;
    x &= (uint64_t)t - 1;
    return x;
}
