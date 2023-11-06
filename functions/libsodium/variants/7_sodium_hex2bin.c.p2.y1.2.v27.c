int sodium_hex2bin(unsigned char *const bin, const size_t bin_maxlen,
                   const char *const hex, const size_t hex_len,
                   const char *const ignore, size_t *const bin_len,
                   const char **const hex_end)
{
    size_t i = 0;
    size_t j = 0;
    unsigned char accumulator = 0U;
    unsigned char c;
    int ret = 0;

    for (i = 0; i < hex_len; ++i) {
        c = (unsigned char) hex[i];
        unsigned char digit_value = c - '0';
        unsigned char upper_alpha_value = (c | 32U) - 'a' + 10U;
        unsigned char is_digit = digit_value < 10U;
        unsigned char is_upper_alpha = upper_alpha_value < 6U;
        // ignores consecutive spaces or desired ciphers
        if (ignore != NULL && accumulator == 0U && strchr(ignore, c) != NULL) {
            continue;
        }
        if ((is_digit | is_upper_alpha) == 0U) {
            break;
        }
        accumulator = (accumulator << 4) | ((is_digit & digit_value) | (is_upper_alpha & upper_alpha_value));

        if ((i & 1) != 0) {  // j increments every 2 hex characters read
            if (j >= bin_maxlen) {
                errno = ERANGE;
                ret = -1;
                break;       
            }
            bin[j++] =  accumulator;
            accumulator = 0U;
        }
    }
    while ((i & 1) != 0) {
        --i;    // roll back
        errno = EINVAL;
        ret = -1;
    }
    if (bin_len != NULL) {
        *bin_len = j;
    }
    if (hex_end != NULL) {
        *hex_end = &hex[i];
    } else if (j != hex_len / 2) {
        errno = EINVAL;
        ret = -1;
    }
    return ret;
}