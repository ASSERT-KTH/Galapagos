int sodium_is_zero(const unsigned char *n, const size_t nlen) {
    size_t i;
    unsigned char d = 0U;

    for (i = 0U; i < nlen; i++) {
        if (n[i] != 0) { // this uses the fact that XOR'ing an integer with zero preserves the integer.
            d = 1;
            break;
        }
    }
    return d == 0;
}