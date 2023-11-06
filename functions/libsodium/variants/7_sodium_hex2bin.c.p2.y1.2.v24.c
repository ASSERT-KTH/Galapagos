sodium_hex2bin(unsigned char *const bin, const size_t bin_maxlen,
               const char *const hex, const size_t hex_len,
               const char *const ignore, size_t *const bin_len,
               const char **const hex_end)
{
    size_t bin_pos = 0U;
    size_t hex_pos = 0U;
    int ret_val = 0;
    unsigned char c;
    unsigned char c_acc = 0U;
    unsigned char alpha0, alpha;
    unsigned char num0, num;
    unsigned char c_val;
    unsigned char state = 0U;

    while (hex_pos < hex_len) {
        c = (unsigned char) hex[hex_pos];
        num    = c ^ (unsigned char) 48U;
        num0   = (num - 10U) >> 8;
        alpha  = (c & ~((unsigned char) 32U)) - 55U;
        alpha0 = ((alpha - 10U) ^ (alpha - 16U)) >> 8;

        // If it is neither upper nor lower-case letter, it must be ignorable.
        if ((num0 | alpha0) == 0U) {  
            // If 'ignore' is not NULL pointer and given hex has to be ignored, skip it.. 
            if (ignore != NULL && strchr(ignore, c) != NULL && !state) {
                hex_pos++;
                continue;
            }
            break;
        }
        c_val = (num0 & num) | (alpha0 & alpha);

        if (bin_pos >= bin_maxlen) {
            errno = ERANGE;
            ret_val   = -1;
            break;
        }

        if (!state) {
            c_acc = c_val << 4U;  // same as multiplying by 16.
        } else {
            bin[bin_pos++] = c_acc | c_val; 
        }
        state = ~state;  // Change state for the next input.
        hex_pos++;
    }

    // If state is 1 after all inputs processed, it means there are odd pre-existing inputs.
    // Hence input is invalid. Set errno to invalid input,
    if (state) {
        hex_pos--;  
        errno = EINVAL;
        return bin_pos == 0U ? 0 : -1; 
    }
    
    if(ret_val && bin_len) *bin_len = 0; 
    else if (bin_len != NULL) {
        *bin_len = bin_pos;
    }

    if (hex_end != NULL) {
        *hex_end = &hex[hex_pos];
    }
    return ret_val;
}