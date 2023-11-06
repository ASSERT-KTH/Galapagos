Here, a program variant of the given code transformed by changing the sequence of operations mainly. Instead of generating the hexadecimal string in place, it waits until completely processing each byte of the binary data. Until then, the partial results are stored in intermediary variables (low and up for lower and upper nibble, respectively). The overall functionality of the code is preserved, that is, converting binary to hexadecimal. See the transformed variant.


sodium_bin2hex(char *const hex, const size_t hex_maxlen,
               const unsigned char *const bin, const size_t bin_len)
{
    size_t      i = (size_t) 0U;
    unsigned int x;
    int          b;
    int          c;
    unsigned char low, up;

    if (bin_len >= SIZE_MAX / 2 || hex_maxlen <= bin_len * 2U) {
        sodium_misuse(); /* LCOV_EXCL_LINE */
    }

    while (i < bin_len) {
        c = bin[i] & 0xf;
        b = bin[i] >> 4;

        up = (unsigned char) (87U + b + (((b - 10U) >> 8) & ~38U));
        low = (unsigned char) (87U + c + (((c - 10U) >> 8) & ~38U));

        hex[i * 2U] = (char) up;
        hex[i * 2U + 1U] = (char) low;
        i++;
    }

    hex[i * 2U] = 0U;

    return hex;
}
