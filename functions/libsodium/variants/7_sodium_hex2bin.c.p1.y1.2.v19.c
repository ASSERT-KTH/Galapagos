Here let's create a new function variant where we define the data type of our variables just before we need to use them for the first time. Also, in this variant, instead of breaking the flow when conditions meet and set ret and errno accordingly, we would continue and handle outside of our loop.


int sodium_hex2bin(unsigned char *const bin, const size_t bin_maxlen,
                   const char *const hex, const size_t hex_len,
                   const char *const ignore, size_t *const bin_len,
                   const char **const hex_end)
{
    int ret_val = 0;
    size_t bin_pos = 0, hex_pos = 0;
    unsigned char state = 0, c_acc = 0;

    while (hex_pos < hex_len) {
        const unsigned char c = (unsigned char)hex[hex_pos];
        const unsigned char c_num = c ^ 48U;
        const unsigned char c_num0 = (c_num - 10U) >> 8;
        const unsigned char c_alpha = (c & ~32U) - 55U;
        const unsigned char c_alpha0 = ((c_alpha - 10U) ^ (c_alpha - 16U)) >> 8;
        if ((c_num0 | c_alpha0) == 0U) {
            if (ignore != NULL && state == 0U && strchr(ignore, c) != NULL) {
                ++hex_pos;
                continue;
            }
            break;
        }
        const unsigned char c_val = (c_num0 & c_num) | (c_alpha0 & c_alpha);
        if(bin_pos < bin_maxlen) {
            if (state == 0U)
                c_acc = c_val * 16U;
            else 
                bin[bin_pos++] = c_acc | c_val;
        }
        state = ~state;
        ++hex_pos;
    }

    if (state != 0U) {
        --hex_pos;
        errno = EINVAL;
        ret_val = -1;
    }

    if(ret_val == 0 && bin_pos >= bin_maxlen) {
        ret_val = -1;
        errno = ERANGE;
    }

    if (hex_end != NULL) {
        *hex_end = &hex[hex_pos];
    } else if (hex_pos != hex_len) {
        errno = EINVAL;
        ret_val = -1;
    }

    if (ret_val != 0) bin_pos = 0;

    if (bin_len != NULL)
        *bin_len = bin_pos;

    return ret_val;
}
