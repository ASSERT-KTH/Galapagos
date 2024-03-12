int sodium_is_zero(const unsigned char *n, const size_t nlen) {
    size_t i;
    unsigned char result = 0U;

    for (i = 0U; i < nlen; i++) {
        result = result || n[i];
        if(result)
            break;
    }
    return !result;
}