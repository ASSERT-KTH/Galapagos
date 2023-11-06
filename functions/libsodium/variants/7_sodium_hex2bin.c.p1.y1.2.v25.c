1) 

int sodium_hex2bin(unsigned char *const bin, const size_t bin_maxlen,
                   const char *const hex, const size_t hex_len,
                   const char *const ignore, size_t *const bin_len,
                   const char **const hex_end) {
    size_t        bin_pos, hex_pos;
    unsigned char c, c_acc, c_alpha, c_num, c_val, state;
    int           ret;

    bin_pos = hex_pos = 0U;
    c_acc = state = 0U;
    ret = 0;

    for (size_t i = 0; i < hex_len; i++) {
        c        = (unsigned char) hex[i];
        c_num    = c ^ 48U;
        c_alpha  = (c & ~32U) - 55U;
        if ((c_num <= 9U) + (c_alpha >= 10U && c_alpha <= 15U) == 0U) {
            if (ignore != NULL && bin_pos%2 == 0 && strchr(ignore, c) != NULL) continue;
            break;
        }
        c_val = (c_num <= 9U) ? c_num : c_alpha-9;
        if (bin_pos/2 >= bin_maxlen) {
            ret   = -1;
            errno = ERANGE;
            break;
        }
        c_acc = (bin_pos%2 == 0) ? c_val*16U : c_acc | c_val;
        if (bin_pos%2 == 1) bin[bin_pos/2] = c_acc;
        bin_pos ++;
    }
    if (bin_pos%2 != 0) {
        bin_pos--;
        errno = EINVAL;
        ret = -1;
    }
    if (ret != 0) bin_pos = 0U;
    if (hex_end != NULL) *hex_end = hex+bin_pos/2;
    else if (bin_pos/2 != hex_len) {
        errno = EINVAL;
        ret = -1;
    }
    if (bin_len != NULL) *bin_len = bin_pos/2;
    return ret;
}


2)

const char hexchrs_numerical[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
const char hexchrs_alpha_lower[6] = {'a', 'b', 'c', 'd', 'e', 'f'};
const char hexchrs_alpha_upper[6] = {'A', 'B', 'C', 'D', 'E', 'F'};

int sodium_hex2bin(unsigned char *const bin, const size_t bin_maxlen,
                   const char *const hex, const size_t hex_len,
                   const char *const ignore,size_t *const bin_len,
                   const char **const hex_end)
{
    size_t bin_pos = 0, hex_pos = 0;
    unsigned char state = 0;
    unsigned char c;
    int val = 0;
    int i;
    int ignore_this_char = 0;
    int ret = 0;
    
    for (hex_pos = 0; hex_pos < hex_len; hex_pos++) {
        c = hex[hex_pos];
        val = -1;
        for (i = 0; (i < 10) && (val == -1); i++)
            if (c == hexchrs_numerical[i]) val = i;
        for (i = 0; (i < 6) && (val == -1); i++)
            if ((c == hexchrs_alpha_lower[i]) || (c == hexchrs_alpha_upper[i]))
                 val = i + 10;

        if (val == -1) {
            if (ignore != NULL && strchr(ignore, c) != NULL && state == 0) {
                continue;
            } else {
                errno = EINVAL;
                return -1;
            }
        }
        
        if (state == 0)  c = val << 4;
        else             bin[bin_pos++] |= val;
        if (bin_pos >= bin_maxlen) {
            ret   = -1;
            errno = ERANGE;
            break;
        }
        state = ~state;

    }
	bin[bin_pos] = '\0';
    if (bin_len != NULL)   *bin_len = bin_pos;
    if (hex_end != NULL)   *hex_end = &hex[hex_pos];
    return ret;
} 
