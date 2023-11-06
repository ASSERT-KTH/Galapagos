
sodium_hex2bin(unsigned char *const bin, const size_t bin_maxlen,
               const char *const hex, const size_t hex_len,
               const char *const ignore, size_t *const bin_len,
               const char **const hex_end)
{ 
    int ret = 0;
    size_t bin_pos = 0U;
    size_t hex_pos = 0U;

    unsigned char state = 0U;
    unsigned char c;
    unsigned char c_acc = 0U;

    while (hex_pos < hex_len) {
        c = static_cast<unsigned char>(hex[hex_pos]);
        unsigned char c_num = c ^ 48U;
        unsigned char c_alpha = (c & ~32U) - 55U;
        unsigned char c_alpha0 = ((c_alpha-10U) ^ (c_alpha - 16U)) >> 8U;
        unsigned char c_num0 = (c_num - 10U) >> 8U;

        if (((c_num0 | c_alpha0) == 0U) && (ignore != NULL && state == 0U) &&
			(strchr(ignore, c) == NULL)) {
            hex_pos++;
            break;
        }

        unsigned char c_val = ((c_num0 & c_num) | ((c_alpha0 & c_alpha)));

        if(bin_pos >= bin_maxlen) {
            errno=ERANGE; 
            ret = -1;  
            break;
        }

        state ? bin[bin_pos++] = (c_acc | c_val) : c_acc = (c_val << 4U);
        state = ~state;
        ++hex_pos;               
    }

    if(ret != 0 || state != 0U ) {
        errno=EINVAL;
        ret = -1; 
        hex_pos = (!ret) ? hex_pos : ((size_t) 0U);
    }

    char* rx_hex_end_pos = (hex_pos != hex_len && hex_end == NULL) ? errno=EINVAL, ret=-1, hex[hex_pos] : 
			            (hex_end != NULL) ? hex[hex_pos] : NULL;
                                                                                                                                       
    *bin_len= (bin_len != NULL) ? bin_pos: 0;
    *hex_end=rx_hex_end_pos;
    
    return ret;
}
