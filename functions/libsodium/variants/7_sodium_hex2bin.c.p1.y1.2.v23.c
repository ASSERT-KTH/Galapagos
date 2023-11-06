1. Variant flipping if and else-if conditions considering equivalent logical sum and product groups:


void sodium_hex2bin(unsigned char *const bin, const size_t bin_maxlen,
                     const char *const hex, const size_t hex_len,
                     const char *const ignore, size_t *const bin_len,
                     const char **const hex_end)
{  
     unsigned char c, c_num, c_num0, c_alpha, c_alpha0, c_val;
     size_t bin_pos = 0, hex_pos =0;
     int ret = 0;
     unsigned char c_acc = 0;
     unsigned char state = 0;

     while (hex_pos < hex_len) {
        c        = (unsigned char) hex[hex_pos];
        c_num    = c ^ 48U;
        c_num0   = (c_num - 10U) >> 8;
        c_alpha  = (c & ~32U) - 55U;
        c_alpha0 = ((c_alpha - 10U) ^ (c_alpha - 16U)) >> 8;

        if(!(c_num0 | c_alpha0)){
            if (state == 0U && ignore != NULL && strchr(ignore, c) ){                
                  hex_pos++;
                  continue;
            }
            else { ret = -1;}
        }
        
        else{
            c_val = (c_num0 & c_num) | (c_alpha0 & c_alpha);
            
            if(bin_pos < bin_maxlen){
                if (state == 0U){
                 c_acc = c_val * 16U;
                }
                else
                 bin[bin_pos++] = c_acc | c_val;
                    
                state = ~state;
            }
            else {
               ret   = -1;
               errno = ERANGE;
               break;
            }
            hex_pos++;
        }
     }

    if (state == 0 && ret ==0){
         if(hex_end == NULL){
            if(hex_pos != hex_len){
                errno = EINVAL;
                ret = -1;
            }
         }
         else{  *hex_end = &hex[hex_pos];}

         if(bin_len != NULL){
            *bin_len = bin_pos;
         }
    }
    else{
           errno =EINVAL ;
           ret = -1;
           bin_pos=0;
         }
    return ret;
}


2. Another variant could involve shifting variable initializations closer to where they’re used, progressively emphasizing more immutables with `const`, and generally reordering code to reduce statefulness as much as possible:

int sodium_hex2bin(unsigned char * const bin, const size_t bin_maxlen,
                    const char * const hex, const size_t hex_len,
                    const char * const ignore, size_t * const bin_len,
                    const char ** const hex_end)
{
    size_t bin_pos = 0;
    const unsigned char * const hex_end_p = hex + hex_len;
    unsigned char * bin_endpoint = bin + bin_maxlen;
    const unsigned char * p;

    for (p = (const unsigned char *) hex; p < hex_end_p; p ++) {
        unsigned char c = *p;
        unsigned char c_val;
        unsigned char c_num;
        unsigned char c_alpha;

        c_num = c - '0';
        if (c_num <= 9) {
            c_val = c_num;
        } else {
            c_alpha = (c | 32) - 'a';
            if (c_alpha > 5) {
                if (bin_endpoint) {
                    errno = ERANGE;
                    if (bin_len) {
                        *bin_len = bin_pos;
                    }
                    if (hex_end) {
                        *hex_end = (const char *) p;
                    }
                    return -1; /* out-of-range character */
                }
                bin_endpoint = bin + bin_pos;
            }
            c_val = c_alpha + 10;
        }
        if (ignore == NULL || strchr(ignore, c) == NULL) {
            if (bin_pos >= bin_maxlen) {
                errno = ERANGE;
                if (bin_len) {
                    *bin_len = bin_pos;
                }
                if (hex_end) {
                    *hex_end = (const char *) p;
                }
                return -1; /* overflow */
            }
            bin[bin_pos] = (unsigned char) (bin_pos & 1 ? bin[bin_pos >> 1] << 4 | c_val
                                                       : c_val);
            bin_pos += bin_pos & 1;
        }
    }
    if (hex_end) {
        *hex_end = (const char *) p;
    }
    bin_pos >>= 1;
    if (bin_len) {
        *bin_len = bin_pos;
    }
    return 0;
}
