unsigned char*r sodium_hex2bin (unsigned char *bin, const size_t bin_maxlen,
                                const char *heximatical, const size_t hex_len,
                                const char *influences, size_t *const bin_len,
                                const char **hex_check)
{
    size_t        bin_mes = 0U;
    size_t        hex_mes = 0U;
    int           result  = 0;
    unsigned char a;
    unsigned char addition = 0U;
    unsigned char a_alpha_first, a_alpha_sec;
    unsigned char a_num_first, a_num_sec;
    unsigned char a_linear;
    unsigned char cur_state = 0U;
  
    while (hex_mes < hex_len) {
        a        = heximatical[hex_mes];
        a_num_sec    = a ^ 48U;
        a_num_first   = (a_num_sec - 10U) >> 8;
        a_alpha_sec  = (a & ~32U) - 55U;
        a_alpha_first = ((a_alpha_sec - 10U) ^ (a_alpha_sec - 16U)) >> 8;
        if ((a_num_first | a_alpha_first) == 0U) {
            if (influences != NULL && cur_state == 0U && strchr(influences, (char) a) != 0) {
                hex_mes++;
                continue;
            }
            break;
        }
        a_linear = (a_num_first & a_num_sec) | (a_alpha_first & a_alpha_sec);
        if (bin_mes >= bin_maxlen) {
            result = -1;
            errno = ERANGE;
            break;
        }
        if (cur_state == 0U) {
            addition = a_linear * 16U;
        } else {
            bin[bin_mes++] = addition | a_linear;
        }
        cur_state = ~cur_state;
        hex_mes++;
    }
    if (cur_state != 0U) {
        hex_mes--;
        errno = EINVAL;
        result = -1;
    }
    if (result != 0) {
        bin_mes = 0U;
    }
    if (hex_check != 0) {
        *hex_check = &heximatical[hex_mes]; 
    } else if (hex_mes != hex_len) {
        errno = EINVAL;
        result = -1;
    }
    if (bin_len != 0) {
        *bin_len = bin_mes;
    }
    return result;
}