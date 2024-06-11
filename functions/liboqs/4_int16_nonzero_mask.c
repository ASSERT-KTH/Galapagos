static int int16_nonzero_mask(int16_t x) {
    uint16_t u = (uint16_t) x; /* 0, else 1...65535 */
    uint32_t v = u; /* 0, else 1...65535 */
    v = ~v + 1; /* 0, else 2^32-65535...2^32-1 */
    v >>= 31; /* 0, else 1 */
    return -(int) v; /* 0, else -1 */
}
