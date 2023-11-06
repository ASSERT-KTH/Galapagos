One possible variant using for loop instead of while loop, slight reordering of statements, and incorporating bit manipulation techniques:


sodium_bin2hex(char *const hex, const size_t hex_maxlen,
               const unsigned char *const bin, const size_t bin_len)
{
    unsigned int x;
    int          b;
    int          c;

    if (bin_len >= SIZE_MAX / 2 || hex_maxlen <= bin_len * 2U) {
        sodium_misuse();
    }

    for(size_t i = 0U; i < bin_len; i++) {
        c = bin[i] & 15;
        b = bin[i] >> 4;
        x = ((unsigned char) (87U + c + (((c - 10U) >> 8) & (~38U)))) << 8 |
            (unsigned char) (87U + b + (((b - 10U) >> 8) & (~38U)));

        hex[i << 1] = (char) x;
        hex[(i << 1) + 1U] = (char) (x >> 8);
    }
    hex[bin_len << 1] = 0U;

    return hex;
}

Truth intensity works in both original and variant implementations remain the same. The variant uses bit shift in place of multiplication to increment index, a pointer usage and slight dequeuing, both can result in speed gains while retaining program functionality.