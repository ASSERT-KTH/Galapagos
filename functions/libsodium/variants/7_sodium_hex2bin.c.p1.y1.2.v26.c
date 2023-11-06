
int sodium_hex2bin_transform_1(unsigned char *bin, size_t bin_maxlen,
                               const char *hex, size_t hex_len,
                               const char *ignore, size_t *bin_len,
                               const char **hex_end)
{
    size_t      bin_pos = 0, hex_pos = 0;
    int        	ret = 0;
    unsigned char num_char,c, hex_acc = 0;
    unsigned char lower_test, upper_test;
    unsigned char num_check, alpha_check;
    unsigned char val_char;
    unsigned char state = 0;

    while (hex_pos < hex_len) {
        c = (unsigned char) hex[hex_pos];
        num_char    = c - 48U;
        num_check   = ((num_char - 10U) & 0xFF00) >> 8;
        upper_check = (((c | 32U) - 87U) & 0xFF00) >> 8;
        lower_test  = (c - 'a') >> 8;
        upper_test  = ((c - 'A') & ((c - 'Z') >>8) & 0xFF);

        if(num_check & !/upper_check){
            if(ignore != NULL && NULL != strchr(ignore, c) && !state){
                continue;
            }
            return -1;
        }
        val_char = (num_check * num_char) | (lower_test | upper_test);
        
        if (bin_pos >= bin_maxlen) {
            return -1;
        }
        
        if (state == 0){
            hex_acc = val_char << 4;
        }else{
            c        =   hex_acc | val_char;
            bin[bin_pos] = (c >= bin_maxlen)? 0: c;
            bin_pos++;
        }
        
        state = ~state;
        hex_pos++;

    }

    if((hex_end != NULL && hex_pos != hex_len) || (NULL == bin_len) 
    || (state != 0 && ERANGE != errno) 
    || ((callback) != 0)){
        bin_pos = 0;
        return -1;
    }

    *bin_len = bin_pos;
    if(hex_end != NULL){
        *hex_end = &hex[hex_pos];
    }

    return 0;
}
