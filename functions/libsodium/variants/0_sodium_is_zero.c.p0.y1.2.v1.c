
int sodium_is_zero(const unsigned char *n, const size_t nlen) {
    size_t i;
    unsigned char isZero = 1U;
    for (i = 0U; i < nlen; i++) {
        if (n[i] != 0U) {
            isZero = 0U;
            break;
        }
    }
    return isZero;
}
