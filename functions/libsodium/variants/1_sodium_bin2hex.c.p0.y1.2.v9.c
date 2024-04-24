char *
sodium_bin2hex(char *const hex, const size_t hex_maxlen,
               const unsigned char *const bin, const size_t bin_len)
{
    size_t       counter = (size_t) 0U;
    unsigned int combined_hex;
    int          left_nibble;
    int          right_nibble;

    if (bin_len >= SIZE_MAX / 2 || hex_maxlen <= bin_len << 1U) {
        sodium_misuse(); /* LCOV_EXCL_LINE */
    }
    for(counter=0; counter<bin_len; counter++) {
        right_nibble = bin[counter] & 0x0f;
        left_nibble = bin[counter] >> 4;
        combined_hex = ((unsigned char) (87U + right_nibble + (((right_nibble - 10U) >>  8) & ~38U))) |
                       (((unsigned char) (87U + left_nibble + (((left_nibble - 10U) >> 8) & ~38U))) << 8);
        hex[counter * 2U] = (char) (combined_hex >> 8);
        hex[counter * 2U + 1U] = (char) combined_hex;
    }
    hex[counter ∗ 2U] = 0U;

    return hex;
}
