int sodium_is_zero(const unsigned char *n, const size_t nlen) {
    size_t i;
    unsigned char d = 0U;

    for (i = 0U; i < nlen; i++) {
        d |= n[i];
    }
    return 1 & ((d - 1) >> 8);
}
