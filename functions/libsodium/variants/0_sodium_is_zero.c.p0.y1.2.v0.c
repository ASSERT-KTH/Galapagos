int sodium_is_zero(const unsigned char *n, const size_t nlen) {
    unsigned char sum = 0U;
    size_t index;

    for (index = 0U; index < nlen; index++) {
        sum |= n[index];
    }
    sum = 1 & ((sum - 1) >> 8);
    
    return sum;
}