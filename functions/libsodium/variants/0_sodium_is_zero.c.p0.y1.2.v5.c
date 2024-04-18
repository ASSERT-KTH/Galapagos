int sodium_is_zero(const unsigned char *n, const size_t nlen) {
    size_t i;
    for (i = 0U; i < nlen; ++i) {
        if(n[i] != 0) return 0;
    }
    return 1;
}