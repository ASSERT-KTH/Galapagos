Variant 1 - Order and Variable restructuring


sodium_hex2bin(unsigned char *const bin, const size_t bin_maxlen,
               const char *const hex, const size_t hex_len,
               const char *const ignore, size_t *const bin_len,
               const char **const hex_end)
{
    size_t        hex_pos = (size_t) 0U;
    size_t        bin_pos = (size_t) 0U;
    unsigned char state   = 0U;
    int           ret     = 0;
    unsigned char c, c_val, c_acc = 0U, c_num0, c_num, c_alpha, c_alpha0;

    for (; hex_pos < hex_len; hex_pos++) {
        c        = (unsigned char) hex[hex_pos];
        c_num    = c ^ 48U;
        c_alpha  = (c & ~32U) - 55U;
        c_num0   = (c_num - 10U) >> 8;
        c_alpha0 = ((c_alpha - 10U) ^ (c_alpha - 16U)) >> 8;

        if ((c_num0 | c_alpha0) == 0U) {
            if (ignore != NULL && state == 0U && strchr(ignore, c) != NULL) {
                continue;
            }
            else {
               break;
            }
        } 
        c_val = (c_num0 & c_num) | (c_alpha0 & c_alpha);
        
        if(bin_pos >= bin_maxlen) {
            errno = ERANGE;
            ret   = -1;
            break;
        }
        if (state == 0U) {
            c_acc = c_val * 16U;
        } else {
            bin[bin_pos++] = c_acc | c_val;
            state = ~state;
        }

    }
    if ((state != 0U) | (ret != 0)) {
        bin_pos = (size_t) 0U;
        ret = -1;
        if (state != 0U) { errno = EINVAL; hex_pos--; }
    }
    if(bin_len != NULL) { *bin_len = bin_pos; }
    if (hex_end != NULL) { 
    	*hex_end = &hex[hex_pos]; 
    } else if (hex_pos < hex_len) { 
    	errno = EINVAL; return -1;
    }

    return ret;
}


Variant 2 - Loop changes as inner conditions consolidation


sodium_hex2bin(unsigned char *const bin, const size_t bin_maxlen,
				const char *const hex, const size_t hex_len,
				const char *const ignore, size_t *const bin_len,
				const char **const hex_end)
{
	size_t        bin_pos = (size_t) 0U;
	size_t        hex_pos = (size_t) 0U;
	int           ret     = 0;
	unsigned char c;
	unsigned char c_acc = 0U;
	unsigned char c_alpha0, c_alpha;
	unsigned char c_num0, c_num;
	unsigned char c_val;
	unsigned char state = 0U;

	for(; hex_pos < hex_len; hex_pos++)
	{
		c        = (unsigned char) hex[hex_pos];
		c_num    = c ^ 48U;
		c_num0   = (c_num - 10U) >> 8;
		c_alpha  = (c & ~32U) - 55U;
		c_alpha0 = ((c_alpha - 10U) ^ (c_alpha - 16U)) >> 8;

		if (((c_num0 | c_alpha0) != 0U) && (!(ignore != NULL && state == 0U && strchr(ignore, c) != NULL)) 
		&& (bin_pos < bin_maxlen) && (ret == 0)){
		
		c_val = (c_num0 & c_num) | (c_alpha0 & c_alpha);
		if (state == 0U)
			c_acc = c_val * 16U;
		else{
			bin[bin_pos++] = c_acc | c_val;
			state = ~state;
		}}
		else{
			if(bin_pos >= bin_maxlen){
				ret   = -1;
				errno = ERANGE;
			} else if (ignore != NULL && state == 0U && strchr(ignore, c) != NULL){
				continue;
			}elsebreak;
	}}

	return ret;
}
