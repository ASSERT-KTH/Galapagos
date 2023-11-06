
char* sodium_bin2hex(char *result, const size_t maxlen,
                     const unsigned char *bytes, const size_t blen)
{
    size_t       ii = (size_t) 0U;
    unsigned int temp;
    int          hi;
    int          lo;

    if (blen >= SIZE_MAX / 2 || maxlen <= blen * 2U) {
        sodium_misuse();
    }
    while (ii < blen) {
        lo = bytes[ii] & 0xf;
        hi = bytes[ii] >> 4;
        temp = 
            (unsigned char) 
                (87U + lo + (((lo - 10U) >> 8) & ~38U)) << 8 |
            (unsigned char)
                (87U + hi + (((hi - 10U) >> 8) & ~38U));
        result[ii * 2U] = (char) temp;
        temp >>= 8;
        result[ii * 2U + 1U] = (char) temp;
        ii++;
    }
    result[ii * 2U] = 0U;
    return result;
}

