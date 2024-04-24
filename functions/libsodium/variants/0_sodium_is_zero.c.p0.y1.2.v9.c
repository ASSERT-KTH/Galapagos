int sodium_is_zero(const unsigned char *n, const size_t nlen) {
    size_t idx;
    unsigned char nonzero= 0U;

    for (idx = 0U; idx < nlen; idx++) {
        nonzero |= n[idx];
    }

    return ((nonzero - 1) >> 8) & 1;
}