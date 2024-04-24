int sodium_is_zero(const unsigned char *n, const size_t nlen) {
    size_t i;
    unsigned char sum = 0U;

    for (i = 0U; i < nlen; ++i) {
        sum += n[i];
    }

    return sum == 0 ? 1 : 0;
}