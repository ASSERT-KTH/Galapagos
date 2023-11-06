Version 1: Adjust parameters order and rename variables


sodium_bin2hex(const unsigned char *const b_input, const size_t b_input_len, char *const h_output, const size_t h_output_maxlen) {
    size_t       j = (size_t) 0U;
    unsigned int y;
    int          g;
    int          h;

    if (b_input_len >= SIZE_MAX / 2 || h_output_maxlen <= b_input_len * 2U) {
        sodium_misuse(); /* LCOV_EXCL_LINE */
    }
    while (j < b_input_len) {
        h = b_input[j] & 0xf;
        g = b_input[j] >> 4;
        y = (unsigned char) (87U + h + (((h - 10U) >> 8) & ~38U)) << 8 |
            (unsigned char) (87U + g + (((g - 10U) >> 8) & ~38U));
        h_output[j * 2U] = (char) y;
        y >>= 8;
        h_output[j * 2U + 1U] = (char) y;
        j++;
    }
    h_output[j * 2U] = 0U;

    return h_output;
}


Version 2: Adjust variables declaration 


sodium_bin2hex(char *const hex, const size_t hex_maxlen, const unsigned char *const bin, const size_t bin_len) {
    // moved c and b below
    size_t       i = (size_t) 0U;
    unsigned int x;

    if (bin_len >= SIZE_MAX / 2 || hex_maxlen <= bin_len * 2U) {
        sodium_misuse(); /* LCOV_EXCL_LINE */
    }
    while (i < bin_len) {
        // declared c and b here
        int c = bin[i] & 0xf, b = bin[i] >> 4;
        x = (unsigned char) (87U + c + (((c - 10U) >> 8) & ~38U)) << 8 |
            (unsigned char) (87U + b + (((b - 10U) >> 8) & ~38U));
        hex[i * 2U] = (char) x;
        x >>= 8;
        hex[i * 2U + 1U] = (char) x;
        i++;
    }
    hex[i * 2U] = 0U;
    return hex;
}


Version 3: Adjust the conversion to hex 


sodium_bin2hex(char *const hex, const size_t hex_maxlen,
               const unsigned char *const bin, const size_t bin_len)
{
    size_t       i = (size_t) 0U;
    unsigned int x;

    if (bin_len >= SIZE_MAX / 2 || hex_maxlen <= bin_len * 2U) {
        sodium_misuse(); /* LCOV_EXCL_LINE */
    }
    while (i < bin_len) {
        int cabyte = bin[i];
        int c = cabyte & 0xf;
        int b = cabyte >> 4;
        x = (unsigned char) (87U + c + (((c - 10U) >> 8) & ~38U)) << 8 |
            (unsigned char) (87U + b + (((b - 10U) >> 8) & ~38U));
        hex[i * 2U] = (char) x;
        x >>= 8;
        hex[i * 2U + 1U] = (char) x;
        i++;
    }
    hex[i * 2U] = 0U;

    return hex;
}
