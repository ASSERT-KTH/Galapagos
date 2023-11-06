
int sodium_hex2bin(unsigned char *const bin, const size_t bin_maxlen,
               const char *const hex, const size_t hex_len,
               const char *const ignore, size_t *const bin_len,
               const char **const hex_end)
{
    size_t hex_pos = 0;
    size_t bin_pos = 0;
    unsigned char state = 0;
    unsigned char c;
    
    for(;hex_pos < hex_len; hex_pos++)
    {
        c = (unsigned char)hex[hex_pos];
        if((c >= '0' && c<= '9') || (c >= 'A' && c <= 'F') || (c >= 'a' && c <= 'f'))
        { 
            if(ignore != NULL && state==0 && strchr(ignore, c) != NULL)
            {
                continue;        
            }
            
            if((c >= '0' && c <= '9')){ 
                c = c - '0'; }
            else if(c >= 'A' && c <= 'F') {
               c = c - 'A' + 10; }
            else if(c >= 'a' && c <= 'f'){
                c = c - 'a' + 10; 
            } 

            if(state == 1) 
            { 
                if(bin_pos >= bin_maxlen)
                {
                    errno = ERANGE;
                    return -1;
                }
                bin[bin_pos++] = bin[bin_pos] << 4 | c; 
                state = 0;
            }
            else {
                bin[bin_pos] = c;
                state = 1; 
            }

              
        }
        else {
            if(state == 1){
            errno = EINVAL;
            return -1;
            }
            break;
        }
    }

    if(bin_len != NULL)
      *bin_len = bin_pos;

    if(hex_end != NULL)
      *hex_end = &hex[hex_pos];


    return 0;
}
