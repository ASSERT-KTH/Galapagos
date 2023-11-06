Variant 1:

int sodium_hex2bin(unsigned char* bin, const size_t bin_maxlen, const char* hex, const size_t hex_len, const char* ignore, size_t* bin_len, const char** hex_end) {
    size_t bin_pos = 0U;
    size_t hex_pos = 0U;
    int result = 0;
    
    unsigned char c, c_accumulate = 0U, c_num, c_alpha;
    
    unsigned char c_num_ideal, c_alpha_ideal;
    unsigned char c_value;
    unsigned char state = 0U;

    
    for (; hex_pos < hex_len; hex_pos++) {
        c = (unsigned char)hex[hex_pos];
        c_num = c ^ 48U;
        c_num_ideal = (c_num - 10U) >> 8;
        c_alpha = (c & ~32U) - 55U;
        c_alpha_ideal = ((c_alpha - 10U) ^ (c_alpha - 16U)) >> 8;

        if ((c_num_ideal | c_alpha_ideal) == 0U) {
           if (ignore != NULL && !state && strchr(ignore, c)) {
                continue;
            }
            break;
        }
        c_value = (c_num_ideal & c_num) | (c_alpha_ideal & c_alpha);
        if (bin_pos >= bin_maxlen) {
            errno = ERANGE;
            result = -1;
            break;
        }
        if (!state) {
           c_accumulate = c_value * 16U;
        } else {
           bin[bin_pos++] = c_accumulate | c_value;
        }
        state = ~state;
    }
    if (state) {
        errno = EINVAL;
        result = -1;
        --hex_pos;
    }
    if (result != 0) {
        bin_pos = 0U;
    }
    if (hex_end != NULL) {
        *hex_end = &hex[hex_pos];
    } else if (hex_pos < hex_len) {
        result = -1;
        errno = EINVAL;
    }
    if (bin_len) {
        *bin_len = bin_pos;
    }
    return result;
}

      In this code, for loop is used instead of while loop, conditions to check whether the pointer is Null have been eliminated and negate logic is added for more straightforward readability.

Variant 2:

int sodium_hex2bin(unsigned char* bin, const size_t bin_maxlen, const char* hex, const size_t hex_len, const char*ignore, size_t* bin_len, const char** hex_end) {
    size_t bin_index = 0U;
    size_t hex_index = 0U;
    int final = 0;

    unsigned char curr_char;
    unsigned char c_alpha_ini;
    unsigned char c_alpha;
    unsigned char c_num_ini;
    unsigned char c_num;
    unsigned char c_value;

    unsigned char state = 0U;

    do {
        curr_char = (unsigned char)hex[hex_index];
        c_num = curr_char ^ 48U;
        c_num_ini = (c_num - 10U) >> 8;
        c_alpha = (curr_char & ~32U) - 55U;
        c_alpha_ini = ((c_alpha - 10U) ^ (c_alpha - 16U)) >> 8;
        if( c_num_ini | c_alpha_ini == 0U ) {
            hex_index = ignore != NULL && strchr(ignore, curr_char) != NULL ? hex_index + 1 : hex_len;
            continue;
        }
        c_value = (c_num_ini & c_num) | (c_alpha_ini & c_alpha);
        if (bin_index >= bin_maxlen) {
            errno = ERANGE;
            final = -1;
            break;
        }
        if(state == 0U) {
            bin[bin_index++] = c_value * 16U;
        } 
        else{
            bin[bin_index++] = bin[bin_index++] | c_value;
        }
        state = ~state;
    } while (++hex_index < hex_len);    
    if(state != 0U) {
        errno = EINVAL;
        final = -1;
        --hex_index;
    }
    if(final != 0) bin_index = 0U;
    hex_end != NULL ? *hex_end = &hex[hex_index] : (hex_index != hex_len)?   (errno = EINVAL, final = -1) : NULL;
    bin_len != NULL ? *bin_len = bin_index : NULL ;
    return final ;
}

    In this transformation, ERROR-related code is added through the ternary operator and modified the control iterate in do while loop. All transformation will keep the original function of generating binary code from hexadecimal code.