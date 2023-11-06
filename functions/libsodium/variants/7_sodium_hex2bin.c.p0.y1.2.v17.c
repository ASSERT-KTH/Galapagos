int sodium_hex2bin(unsigned char *bin, size_t bin_maxlen,
                   const char *hex, size_t hex_len,
                   const char *ignore, size_t *bin_len,
                   const char **hex_end)
{
    size_t        bin_i = 0U;
    size_t        hex_i = 0U;
    int           status     = 0;
    unsigned char character;
    unsigned char accumulator = 0U;
    unsigned char c_alpha1, c_alpha2;
    unsigned char c_num1, c_num2;
    unsigned char c_val_res;
    unsigned char state_flag = 0U;

    while (hex_i < hex_len) {
        character          = (unsigned char) hex[hex_i];
        c_num1             = character ^ 48U;
        c_num2             = (c_num1 - 10U) >> 8;
        c_alpha2       = (character & ~32U) - 55U;
        c_alpha1 = ((c_alpha2 - 10U) ^ (c_alpha2 - 16U)) >> 8;
        if ((c_num2 | c_alpha1) == 0U) {
            if (ignore != NULL && state_flag == 0U && strchr(ignore, character) != NULL) {
                hex_i++;
                continue;
            }
            break;
        }
        c_val_res = (c_num2 & c_num1) | (c_alpha1 & c_alpha2);
        if (bin_i >= bin_maxlen) {
            status   = -1;
            errno = ERANGE;
            break;
        }
        if (state_flag == 0U) {
            accumulator = c_val_res * 16U;
        } else {
            bin[bin_i++] = accumulator | c_val_res;
        }
        state_flag ^= 1U;
        hex_i++;
    }
    if (state_flag) {
        hex_i--;
        errno = EINVAL;
        status = -1;
    }
    if (status != 0) {
        bin_i = 0U;
    }
    if (hex_end) {
        *hex_end = &hex[hex_i];
    } else if (hex_i != hex_len) {
        errno = EINVAL;
        status = -1;
    }
    if (bin_len) {
        *bin_len = bin_i;
    }
    return status;
}
