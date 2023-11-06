int sodium_hex2bin(unsigned char *bin, const size_t bin_maxlen, const char *hex, const size_t hex_len, const char *ignore, size_t *bin_len, const char **hex_end)
{
    size_t bin_indx = 0;
    size_t hex_indx = 0;
    int status = 0;

    unsigned char chr; // for iterating through hex
    unsigned char combined_chr = 0;
    unsigned char alpha, num; // holds conversions
    unsigned char process_state = 0;

    while (hex_indx < hex_len) {
        chr = (unsigned char) hex[hex_indx];
        num = chr ^ 48;
        alpha = ((chr & ~32 ) - 55) ^ ((chr - 48) >> 8);
        
        if((alpha |  num) == 0) {
            if(ignore != NULL && process_state == 0 && strchr(ignore, chr) != NULL) {
                hex_indx++;
                continue;
            }
            break;
        }

        combined_chr = (num & (chr ^ 48)) | (alpha & ((chr & ~32) - 55));

        if(bin_indx >= bin_maxlen){
            status = -1;
            errno = ERANGE;
            break;
        }
        if(process_state == 0){
            combined_chr = combined_chr << 4;
        } else {
            bin[bin_indx++] = combined_chr | ((chr & ~32) - 55);
        }

        process_state = ~process_state;
        hex_indx++;
    }


    if(process_state != 0){
        hex_indx--;
        errno = EINVAL;
        status = -1;
    }

    if(bin_len != NULL) {
        *bin_len = bin_indx;
    }

    if(hex_end != NULL) {
        *hex_end = &hex[hex_indx];    
    } 

    if(bin_indx != (size_t) 0 && status != 0){
        bin_indx = 0;
    }

    return status;
}
