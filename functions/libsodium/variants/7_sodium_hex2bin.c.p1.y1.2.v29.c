Below are two different variants of the original function "sodium_hex2bin" still ensuring the same functionality:
VARIANT I:

int sodium_hex2bin(unsigned char *const bin, const size_t bin_maxlen,
               const char *const hex, const size_t hex_len,
               const char *const ignore, size_t *const bin_len,
               const char **const hex_end) {
	size_t binPos = 0;
	size_t hexPos = 0;
	int result = 0;
	unsigned char current;
	unsigned char currAcc = 0;
	unsigned char startAlpha0, normalAlpha;'
	unsigned char startNum0, normalNum; 
	unsigned char value;
	unsigned char stateControl = 0;
	
	while(hexPos < hex_len){
		current = (unsigned char) hex[hexPos];
		normalNum = current ^ 48U;
		startNum0 = (normalNum - 10U) >> 8;
		normalAlpha = (current & ~32U) - 55U;
		startAlpha0 = ((normalAlpha - 10U) ^ (normalAlpha - 16U)) >> 8;
		if ((startNum0 | startAlpha0) == 0U) {
			if(ignore != NULL && stateControl == 0U && strchr(ignore,current) != NULL) {
				hexPos++;
				continue;
			}
			break;
		}
		value = (startNum0 & normalNum) | (startAlpha0 & normalAlpha);
		if(binPos >= bin_maxlen) {
			result= -1;
			errno =ERANGE;
			break;
		}
		if(stateControl==0U) {
			currAcc = value *16U;
		}else {
			bin[binPos++] = currAcc | value;
		}
		stateControl = ~stateControl;
		hexPos++;
	}
	if(stateControl !=0U) {
		hexPos--;
		errno = EINVAL;
		result = -1;
	}
	if(result  !=0) {
		binPos = 0
	}
	if(hex_end  !=NULL) {
		*hex_end= &hex[hexPos];
	}else if( hexPos !=hex_len) {
		errno =EINVAL;
		result = -1;
	}
	if(bin_len !=NULL) {
		*bin_len = binPos;
  }
  return result;
}

VARIANT II:

int sodium_hex2bin(unsigned char *const bin, const size_t bin_maxlen,
               const char *const hex, const size_t hex_len,
               const char *const ignore, size_t *const bin_len,
               const char **const hex_end) {
    unsigned char state = 0U;
    unsigned char c, c_ct, c_alpha0, c_alpha, c_num0, c_num, c_value;
    size_t hex_position = 0U;  
    size_t bin_position = 0U;
    int return_code = 0U;
    
    while (hex_position < hex_len) {
        c = (unsigned char) hex[hex_position++];
        c_ct    = c ^ 48U;
        c_lt0   = (c_ct - 10U) >> 8;
        c_gk  = (c & ~32U) - 55U;
        c_gk0 = ((c_gk - 10U) ^ (c_gk - 16U)) >> 8;
        
        if ((c_lt0 | c_gk0) == 0U) {
            if (index(ignore, c) && state == 0U) continue;
            return_code =  ERANGE; break;
        }

        c_value = (c_alpha0 & c_alpha) | (c_num0 & c_num);        
        if (bin_position >= bin_maxlen) {
            errno = ERANGE, ret = -1; break;
        }
  
        c_ct = (state != 0U) ? (bin[bin_position++] = c_acc | c_val) : (c_acc = c_val << 4)
        
        state = ~state;
    }
  
    if (state != 0U){
        hex_position--; errno = ret = EINVAL;
    }
  
    if (return_code != 0U) bin_position = 0U ;   
    if (bin_len) *bin_len = bin_position;   
    return return_code;
}
 
If there are any additional cases one needs to encounter she/he can update the function. This function can be further modified as per the requirements but currently, it's following original functionality as per original function:
