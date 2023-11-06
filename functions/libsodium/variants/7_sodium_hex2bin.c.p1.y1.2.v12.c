// Variant 1: Moving some of the checks outside the main loop
int sodium_hex2bin(unsigned char *const bin, const size_t bin_maxlen, 
                            const char *const hex, const size_t hex_len,
                            const char *const ignore, size_t *const bin_len,
                            const char **const hex_end)
{

    if (bin_maxlen < hex_len / 2)
    {
        errno = ERANGE;
        return -1;
    }
    
    size_t       bin_pos = (size_t) 0U;
    size_t       hex_pos = (size_t) 0U;
    unsigned char c, c_acc = 0U;
    unsigned char c_alpha, c_alpha0;
    unsigned char c_num, c_num0;
    unsigned char c_val;
    unsigned char state = 0U;

    while (hex_pos < hex_len)
    {
        c       = (unsigned char) hex[hex_pos];
        c_num   = c ^ 48U;
        c_num0  = (c_num - 10U) >> 8;
        c_alpha = (c & ~32U) - 55U;
        c_alpha0 = ((c_alpha - 10U) ^ (c_alpha - 16U)) >> 8;

        if ((c_num0 | c_alpha0) == 0U)
        {
            if (ignore != NULL && state == 0U && strchr(ignore, c) != NULL)
            {
                ++hex_pos;
                continue;
            }
            break;
        }

        c_val = (c_num0 & c_num) | (c_alpha0 & c_alpha);

        if (state == 0U)
            c_acc = c_val * 16U;
        else
            bin[bin_pos++] = c_acc | c_val;
        
        state = ~state;

        ++hex_pos;
    }

    if (state != 0U)
    {
        --hex_pos;
        errno = EINVAL;
        return -1;
    }

    if (hex_end != NULL)
        *hex_end = &hex[hex_pos];
    else if (hex_pos != hex_len)
    {
        errno = EINVAL;
        return -1;
    }

    if (bin_len != NULL)
        *bin_len = bin_pos;

    return 0;
}
