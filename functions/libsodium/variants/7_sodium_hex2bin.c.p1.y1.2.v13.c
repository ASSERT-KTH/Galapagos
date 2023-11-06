Variant 1: Here, changed the order of if-else if, this variant would check if hex_pos != hex_len before checking if hex_end is NULL:


int sodium_hex2bin(unsigned char *const bin, const size_t bin_maxlen, 
                   const char *const hex, const size_t hex_len,
                   const char *const ignore, size_t *const bin_len,
                   const char **const hex_end)
{
    size_t bin_pos = 0U, hex_pos = 0U;
    int ret = 0;
    unsigned char state = 0U, c, c_acc;
    
    while (hex_pos < hex_len) {
    	c = (unsigned char) hex[hex_pos];
    	unsigned char c_num = c ^ 48U, 
                      c_num0 = (c_num - 10U) >> 8,
                      c_alpha = (c & ~32U) - 55U,
                      c_alpha0 = ((c_alpha - 10U) ^ (c_alpha - 16U)) >> 8;
                      
    if ((c_num0 | c_alpha0) == 0U) {
    		
       if (ignore != NULL && state == 0U && strchr(ignore, c) != NULL) {
          hex_pos++;
          continue;
       }
        break;
    }
    unsigned char c_val = (c_num0 & c_num) | (c_alpha0 & c_alpha);
    	
    if (bin_pos >= bin_maxlen) {
       ret = -1;
       errno = ERANGE;
       break;
    }
    if (state == 0U) {
       c_acc = c_val * 16U;
    } else {
       bin[bin_pos++] = c_acc | c_val;
    }
    state = ~state;
    hex_pos++;
}
    
if (state != 0U) {
    hex_pos--;
    errno = EINVAL;
    ret = -1;
}
if (ret != 0) {
    bin_pos = 0U;
}
    
if (hex_pos != hex_len) {
    errno = EINVAL;
    ret = -1;
} else if (hex_end != NULL) {
    *hex_end = &hex[hex_pos];
}
    
if (bin_len != NULL) {
    *bin_len = bin_pos;
}
return ret;
}

  
Variant 2: Compressed some conditional initializations and loops to single lines:


int sodium_hex2bin(unsigned char *const bin, const size_t bin_maxlen, 
                   const char *const hex, const size_t hex_len, const char *const ignore, size_t *const bin_len,
		            const char **const hex_end)
{
    size_t bin_pos = 0U, hex_pos = 0U;
    int ret = 0;
    unsigned char state = 0;

    while (hex_pos < hex_len) {
    	unsigned char c = (unsigned char) hex[hex_pos],
		                  c_num = c ^ 48U,
		                  c_num0 = (c_num - 10U) >> 8,
		                  c_alpha = (c & ~32U) - 55U,
		                  c_alpha0 = ((c_alpha - 10U) ^ (c_alpha - 16U)) >> 8;

    if ((c_num0 | c_alpha0) == 0U) {
    	if (ignore != NULL && state == 0U && strchr(ignore, c) != NULL) {
        	hex_pos++;
            continue;
        }
        break;
    }
      
    unsigned char c_val = (c_num0 & c_num) | (c_alpha0 & c_alpha);
    ret = bin_pos >= bin_maxlen ? for_init(&state, &bin, &bin_pos, c_val, -1) : ret;
        
    state = ~state;
    hex_pos++;
}

state == 0U ? hex_pos : state_fun(&state, &hex_pos, &ret);
    
if (hex_end != NULL) {
    *hex_end = &hex[hex_pos];
} else if (hex_pos != hex_len) {
    errno = EINVAL;
    ret = -1;
}
   
if (bin_len != NULL) {
    *bin_len = bin_pos;
}
    
unistd(ret != 0 ? reset(&bin_pos) : bin_pos);
return ret;
}
		           	           				
int reset(size_t *bin_pos) {
     *bin_pos = (size_t)0U;
     return -1;
}

int for_init(unsigned char *state, unsigned char **bin, size_t *bin_pos, unsigned char c_val, int ret) {
    if (*state == 0) {
       *state = c_val <<= 4;
    } else {
        *bin++[((*bin_pos)++)] = *state | c_val;
    };
    errno = ERANGE;
    return ret;
}

void state_fun(unsigned char *state, size_t *hex_pos, int *ret) {
    if (*state != 0U) {
        --(*hex_pos);
        errno = EINVAL;
        *ret = -1;
    }
}
}
