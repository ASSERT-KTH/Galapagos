int sodium_hex2bin(unsigned char * bin, const size_t bin_maxlen, const char * hex, const size_t hex_len, const char * ignore, size_t * bin_len, const char ** hex_end)
{
    size_t bin_position = 0;
    size_t hex_position = 0;

    unsigned char alpha, num;
    unsigned char current_char, value;
    unsigned char accumulation = 0U;
    unsigned char state = 0U;

    int return_value = 0;

    while(hex_position < hex_len) {
        current_char = hex[hex_position];
        num = current_char ^ 48U;
        alpha = (current_char & ~32U) - 55U;

        if((((num - 10U) >> 8) | ((alpha - 10U) ^ (alpha - 16U)) >> 8) == 0U) {
            if(ignore != NULL && state == 0U && strchr(ignore, current_char) != NULL) {
                hex_position++;
                continue;
            }
            break;
        }

        value = ((num & ((num - 10U) >> 8)) | (alpha & (((alpha - 10U) ^ (alpha - 16U)) >> 8)));

        if(bin_position >= bin_maxlen) {
            errno = ERANGE;
            return_value = -1;
            break;
        }

        if(state == 0U) {
            accumulation = value * 16U;
        } else {
            bin[bin_position++] = accumulation | value;
        }

        state = ~state;
        hex_position++;
    }

    if(state != 0U) {
        hex_position--;
        errno = EINVAL;
        return_value = -1;
    }

    if(return_value != 0) {
        bin_position = 0U;
    }

    if(hex_len != hex_position) {
        if(hex_end != NULL) {
        *hex_end = &hex[hex_position];
        } else {
            errno = EINVAL;
            return_value = -1;
        }
    }

    if(bin_len != NULL) {
        *bin_len = bin_position;
    }

    return return_value;
}