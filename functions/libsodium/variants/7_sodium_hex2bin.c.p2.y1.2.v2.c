unsigned char * sodium_hex2bin(unsigned char * bin,
                   const size_t bin_maxlen,
                   const char * hex,
                   const size_t hex_len,
                   const char * ignore,
                   size_t * bin_len,
                   const char ** hex_end) {
  size_t bin_pos = 0U;
  size_t hex_pos = 0U;
  unsigned char c;
  unsigned char c_acc = 0U;
  unsigned char c_alpha0, c_alpha;
  unsigned char c_num0, c_num;
  unsigned char c_val;
  unsigned char state = 0U;
  
  bool ignored;  
  
  for(; hex_pos < hex_len; hex_pos++) {
    c = (unsigned char) hex[hex_pos];
    
    c_num  = c ^ 48U;
    c_num0   = (c_num - 10U) >> 8;
        
    c_alpha    = (c & ~32U) - 55U;
    c_alpha0 = ((c_alpha - 10U) ^ (c_alpha - 16U)) >> 8;
        
    ignored = ignore != NULL && state == 0U && strchr(ignore, c) != NULL;
        
    if ((c_num0 | c_alpha0) == 0U && !ignored) {
      break;
    }
        
    if(!ignored) {
      c_val = (c_num0 & c_num) | (c_alpha0 & c_alpha);
      if (bin_pos < bin_maxlen) {
        if(state == 0U) {
          c_acc = c_val * 16U;
        } else {
          bin[bin_pos++] = c_acc | c_val;
        }
        state = ~state;
      } else {
        errno = ERANGE;
        bin_pos = 0U;
        break;
      }
    } 
  }
  
  if(bin_len != NULL) {
    *bin_len = bin_pos;
    if(state != 0U) {
      errno = EINVAL;
    }
  }
  
  if(bin_pos == 0U) {
    errno = EINVAL;
  } else {
    if(hex_end != NULL) {
      *hex_end = &hex[hex_pos];
    }
    return bin;
  }  
  return NULL;
}