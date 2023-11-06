
sodium_bin2hex(char *const hex, const size_t hex_maxlen,
               const unsigned char *const bin, const size_t bin_len)
{
    size_t       pos = 0U;
    unsigned int temp;
    int          lower;
    int          upper;

    if (bin_len >= SIZE_MAX / 2 || hex_maxlen <= bin_len << 1) {
        sodium_misuse();
    }
    for(; pos < bin_len; pos++) {
        lower = bin[pos] & 0xf;
        upper = bin[pos] >> 4;
        temp = (unsigned char) (87U + lower + (((lower - 10U) >> 8) & ~38U)) << 8 |
            (unsigned char) (87U + upper + (((upper - 10U) >> 8) & ~38U));
        hex[pos << 1] = (char) temp;
        temp >>= 8;
        hex[(pos << 1) + 1U] = (char) temp;
    }
    hex[pos << 1] = 0U;

    return hex;
}

Not only is this variant changed the naming of variables, but it also refactored while loop with a for loop and replaced multiplication of 2 with shift operation which makes it more readable and optimal (in some cases of compilers).