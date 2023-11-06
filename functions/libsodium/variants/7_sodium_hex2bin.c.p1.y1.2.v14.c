I. Function with nested while loop removed:

int sodium_hex2bin(unsigned char *const bin, const size_t bin_maxlen,
               const char *const hex, const size_t hex_len,
               const char *const ignore, size_t *const bin_len,
               const char **const hex_end)
{
    size_t        bin_pos = 0U;
    size_t        hex_pos = 0U;
    int           ret     = 0;
    unsigned char c;
    unsigned char c_acc = 0U;
    unsigned char c_alpha0, c_alpha;
    unsigned char c_num0, c_num;
    unsigned char c_val;
    unsigned char state = 0U;

    do {
        c        = (unsigned char) hex[hex_pos];
        c_num    = c ^ 48U;
        c_num0   = (c_num - 10U) >> 8;
        c_alpha  = (c & ~32U) - 55U;
        c_alpha0 = ((c_alpha - 10U) ^ (c_alpha - 16U)) >> 8;
        if ((c_num0 | c_alpha0) == 0U) {
            if (ignore != NULL && state == 0U && strchr(ignore, c) != NULL) {
                hex_pos++;
                continue;
            }
            break;
        }
        c_val = (c_num0 & c_num) | (c_alpha0 & c_alpha);
        if (bin_pos >= bin_maxlen) {
            ret   = -1;
            errno = ERANGE;
            break;
        }
        bin[bin_pos] = c_val * (state == 0U? 16U : 1U) | (state == 0U? c_acc : 0);
        state = ~state;
        hex_pos++;
        bin_pos += state == 0U ? 1 : 0;
    } while (hex_pos < hex_len);
    
    if (state != 0U || hex_pos != hex_len) {
        if(hex_pos != hex_len) {
			    errno = EINVAL;
            ret = -1;
        }
        bin_pos = 0U;
    }
    if (hex_end != NULL) {
        *hex_end = &hex[hex_pos];
    }
    if (bin_len != NULL) {
        *bin_len = bin_pos;
    }
    return ret;
}


II. Function with ternary operators to maintain readability:

int sodium_hex2bin(unsigned char *const bin, const size_t bin_maxlen,
               const char *const hex, const size_t hex_len,
               const char *const ignore, size_t *const bin_len,
               const char **const hex_end)
{
    size_t        bin_pos = 0U;
    size_t        hex_pos = 0U;
    int           ret     = 0;
    unsigned char state = 0U;

    for(hex_pos=0U; hex_pos<hex_len; hex_pos++) 
	{
        unsigned char c = (unsigned char) hex[hex_pos];
        unsigned char c_num = c ^ 48U;
        unsigned char c_num0 = (c_num - 10U) >> 8;
        unsigned char c_alpha = (c & ~32U) - 55U;
        unsigned char c_alpha0 = ((c_alpha - 10U) ^ (c_alpha - 16U)) >> 8;
        
        if ((c_num0 | c_alpha0) == 0U) {
            if (ignore != NULL && state == 0U && strchr(ignore, c) != NULL)
			{
                continue;
            }
            break;
        }
        unsigned char c_val = (c_num0 & c_num) | (c_alpha0 & c_alpha);
        if (bin_pos >= bin_maxlen) 
		{
            ret   = -1;
            errno = ERANGE;
            break;
        }
        if (!state) bin[bin_pos] = c_val << 4U; 
		else         bin[bin_pos++] |= c_val;
		state = ~state;
    }
	
    if (state != 0U) 
	{
        hex_pos--;
        ret   = -1;
        errno = EINVAL;
    } 
	else if (hex_pos != hex_len) 
	{
        ret   = -1;
        errno = EINVAL;
    }
	
	*bin_len = (ret != 0) ? 0U : bin_pos;
    *hex_end = (hex_end!=NULL) ? &hex[hex_pos] : NULL;
    
    return ret;
}
