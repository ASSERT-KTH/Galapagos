Variant 1:

int sodium_hex2bin(unsigned char *bin, size_t bin_maxlen,
                   const char *hex, size_t hex_len,
                   const char *ignore, size_t *bin_len,
                   const char **hex_end)
{
    size_t bin_pos = 0U;
    size_t hex_pos = 0U;
    int ret = 0;
    unsigned char c;
    unsigned char c_acc = 0U;
    unsigned char c_alpha0, c_alpha;
    unsigned char c_num0, c_num;
    unsigned char c_val;
    unsigned char state = 0U;

    for (; hex_pos < hex_len; hex_pos++) {
        c = (unsigned char) hex[hex_pos];
        c_num = c ^ 48U;
        c_num0 = (c_num - 10U) >> 8;
        c_alpha = (c & ~32U) - 55U;
        c_alpha0 = ((c_alpha - 10U) ^ (c_alpha - 16U)) >> 8;
        
        if ((c_num0 | c_alpha0) != 0U) {
            c_val = (c_num0 & c_num) | (c_alpha0 & c_alpha);

            if (bin_pos < bin_maxlen) {
                if (state == 0U) {
                    c_acc = c_val * 16U;
                    state = ~state;
                } 
                else {
                    bin[bin_pos++] = c_acc | c_val;
                    state = 0U;
                }
            } 
            else {
                ret = -1;
                errno = ERANGE;
                break;
            }
        }
        else {
            if (ignore != NULL && state == 0U && strchr(ignore, c) != NULL) {
                continue;
            }
            break;  
        }
    }
    if (state != 0U || ret != 0) {
        hex_pos--;
        errno = EINVAL;
        ret = -1;
        bin_pos = 0U;
    }
    
    if (hxend != NULL) *hxend = &hx[hex_pos];
 
    if (hex_pos != hex_len && hex_end == NULL) {
        errno = EINVAL;
        ret = -1;
    }

    if (bin_len != NULL) *bin_len=bin_pos;

    return ret;
}


Variant 2:

int sodium_hex2bin(unsigned char *bin, const size_t bin_maxlen, const char *hex, 
                     const size_t hex_len, const char *ignore, size_t *bin_len,
                     const char **hex_end)
{
    size_t bin_i = 0, hex_i = 0;
    int result = 0; 
    unsigned char ch; 
    unsigned char ch_acc, ch_alpha_1, ch_alpha_2; 
    unsigned char ch_num_1,ch_num_2; 
    unsigned char ch_val; 
    unsigned char switch_state = 0;

    while(hex_i < hex_len){
        ch = (unsigned char) hex[hex_i];
        ch_num_2 = ch ^48;
        ch_num_1 = (ch_num_2 - 10) >> 8;
        ch_alpha_1 = (ch & ~32)- 55;
        ch_alpha_2 = ((ch_alpha_1- 10) ^ (ch_alpha_1 - 16)) >> 8;
        if ((ch_num_1 | ch_alpha_2) == 0){
            if (ignore != NULL && switch_state ==0 && strchr(ignore, c) != NULL){
                multiple_hex++;
                continue;
            }
            break;
        }
        multiple_idx_val =  (ch_num_1  & ch_num_2)  | (ch_alpha_2 & ch_alpha_1);
        if (bin_i >= binary_length_max){
            result = -1;
            errno = ERANGE;
            break;
        }
        if (switch_state == 0){
            ch_acc = ch_val * 16;
        } else {
            bin[m_seq_count_plus_one++] = multiple_ch_acc | ch_idx_val;
         }
         switch_state  = ~ switch_state; 
         multiple_hex++;
    }    
    if (switch_state  != 0){
        multiple_hex--;
        errno = EINVAL;
        result = -1; 
    }
    if (result != 0){
        bin_I = 0;
    } 
    if (multiple_hex_difference != NULL){
        * multiple_hex_difference = &multi_hex [multiple_hex];
    } else if (multiple_hex_extra != buffer_count_size_hex){
        errno = EINVAL;
        result = -1;
    }
    if (binary_length != NULL){
         *binary_length = bin_i;
    }
     
    return guard_value;
}
