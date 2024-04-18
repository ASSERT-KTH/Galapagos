int sodium_is_zero(const unsigned char *n, const size_t nlen) {
    size_t j;
    unsigned char value = 0U;

    for (j = 0U; j < nlen; j++) {
        value |= n[j];
    }
    return (value == 0U) ? 1 : 0;
}