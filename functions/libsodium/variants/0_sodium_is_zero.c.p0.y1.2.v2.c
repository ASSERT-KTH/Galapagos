int sodium_is_zero(const unsigned char *n, const size_t nlen) {
    unsigned char d = 0U;
    size_t i = 0U;
    while(i < nlen && d == 0U) {
        d |= n[i++];
    }
    return ((d - 1) & 0x100) == 0;
}