Variant 1:


int sodium_hex2bin(unsigned char *const bin, const size_t bin_maxlen,
               const char *const hex, const size_t hex_len,
               const char *const ignore, size_t *const bin_len,
               const char **const hex_end) {
    int ret = 0;
    size_t pos = (size_t) 0U;
    
    unsigned char val, acc = 0U;
    unsigned char alpha, alpha0, num, num0;

    unsigned char state = 0U;

    for (size_t i = 0; i < hex_len; ++i) {
        unsigned char curChar  = (unsigned char) hex[i];
        
        num    = curChar ^ 48U;
        num0   = (num - 10U) >> 8;
        
        alpha  = (curChar & ~32U) - 55U;
        alpha0 = ((alpha - 10U) ^ (alpha - 16U)) >> 8;

        if ((num0 | alpha0) == 0U) {
            if (ignore != NULL && state == 0U && strchr(ignore, curChar) != NULL) {
                continue;
            }
            else {
                break;
            }
        }

        val = (num0 & num) | (alpha0 & alpha);

        if (pos >= bin_maxlen) {
            ret   = -1;
            errno = ERANGE;
            break;
        }
        
        state == 0U ? (acc = val * 16U) : (bin[pos++] = acc | val);
		
        state = ~state;
    }
    
    if (state != 0U) {
	errno = EINVAL;
    	ret = -1;
    }

    if (ret != 0) {
       pos = (size_t) 0U;
    }
 
    if (hex_end != NULL) {
        *hex_end = &hex[pos];
    } else if (pos != hex_len) {
        errno = EINVAL;
        ret = -1;
    }

    if (bin_len != NULL) {
        *bin_len = pos;
    }

    return ret;
}
	
  
Variant 2:


int sodium_hex2bin(unsigned char *const bin, const size_t bin_maxlen,
                   const char *const hex, const size_t hex_len,
                   const char *const ignore, size_t *const bin_len,
                   const char **const hex_end)
{
    size_t pos = 0U;
    int error_status = 0;

    unsigned char cur_char;
    unsigned char primary_accumulator = 0U;
    unsigned char num_val, num_0, alpha_val, alpha_0;
    unsigned char hex_to_bin_val;

    unsigned char current_state = 0U;

    for(; pos < hex_len; pos++) {
        cur_char = (unsigned char) hex[pos];

        num_val = cur_char ^ 48U;
        num_0 = (num_val - 10U) >> 8;

        alpha_val = (cur_char & ~32U) - 55U;
        alpha_0 = ((alpha_val - 10U) ^ (alpha_val - 16U)) >> 8;

        if (!(num_0 | alpha_0)) {
            if (ignore!=0 && !current_state && strchr(ignore, cur_char)){
                continue;
            }
            break;
        }

        hex_to_bin_val = (num_0 & num_val) | (alpha_0 & alpha_val);

        if (pos >= bin_maxlen) {
            error_status = -1;
            errno = ERANGE;
            break;
        }

        if(!current_state) {
            primary_accumulator = hex_to_bin_val * 16U;
        } else {
            bin[pos] = primary_accumulator | hex_to_bin_val;
        }
 
        current_state = ~current_state;
    }

    if(current_state) {
        pos--;
        error_status = -1;
        errno = EINVAL;
    }

    if (!error_status) {
        pos = (size_t) 0U;
    }

    *hex_end == NULL ? (pos != hex_len ? errno = EINVAL : error_status = -1) : (*hex_end = &hex[pos]);
    if (bin_len != NULL) {
        *bin_len = pos;
    }

    return error_status;
}
