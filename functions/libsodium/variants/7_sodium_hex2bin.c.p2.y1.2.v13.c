int sodium_hex2bin(unsigned char *const bin, const size_t bin_maxlen,
                   const char *const hex, const size_t hex_len,
                   const char *const ignore, size_t *const bin_len,
                   const char **const hex_end)
{
    size_t bin_pos = 0U;
    size_t hex_pos = 0U;
    
    int result = 0;    // replace usage of "ret"
    unsigned char character; // used "character" for better understandability

    unsigned char c_acc = 0U;
    unsigned char symbol_alpha0, symbol_alpha; // used more descriptive names instead of c_alpha, c_alpha0
    unsigned char symbol_num0, symbol_num; // used more descriptive names instead of c_num, c_num0
    unsigned char c_val;
    unsigned char state = 0U;

    for(; hex_pos<hex_len; hex_pos++){    // change while loop to for
        character = (unsigned char) hex[hex_pos];
        symbol_num = character ^ 48U;
        symbol_num0 = (symbol_num - 10U) >> 8;
        symbol_alpha = (character & ~32U) - 55U;
        symbol_alpha0 = ((symbol_alpha - 10U) ^ (symbol_alpha - 16U)) >> 8;
        
        if ((symbol_num0 | symbol_alpha0) != 0U) {
            if (ignore != NULL && state == 0U && strchr(ignore, character) != NULL) {
                continue;
            }
            break;
        }
        c_val = (symbol_num0 & symbol_num) | (symbol_alpha0 & symbol_alpha);

        if (bin_pos >= bin_maxlen) {
            errno = ERANGE;
            result = -1;        // replaced line with use of result               
            break;
        }
        bin[bin_pos] = (state == 0U) ? (c_acc=c_val*16U) : (bin[bin_pos++]=c_acc|c_val);
        state = ~state;
    }
    
    if (state != 0U) {
        hex_pos--;
        errno = EINVAL;
        result = -1;
    }
    
    if (!result) {                // replacing ret usage
        bin_pos = 0;              // replaced type cast
    }
    
    if (hex_end != NULL) {
        *hex_end = &hex[hex_pos];
    } else if (hex_pos != hex_len) {
        errno = EINVAL;
        return -1;                // changing immediate function ending rather then using result variable
    }

    if (bin_len != NULL) {
        *bin_len = bin_pos;
    }

    return result;
}