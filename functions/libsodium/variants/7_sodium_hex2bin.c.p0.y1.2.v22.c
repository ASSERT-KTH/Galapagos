int sodium_hex2bin(unsigned char * bin, const size_t bin_maxlen,
               const char * hex, const size_t hex_len,
               const char * ignore, size_t * bin_len,
               const char ** hex_end)
{
    size_t        bin_size = 0;
    size_t        hex_size = 0;
    unsigned char * result = bin;

#define IS_HEX(c) (((c >= '0') && (c <= '9')) || ((c >= 'A') && (c <= 'F')) || ((c >=  'a') && (c <= 'f')))
#define TO_BIN(h) (h >= 'A' ? (h >= 'a' ? h - 'a' + 10 : h - 'A' + 10) : h - '0')

    while(hex_size<hex_len) {
        if(!IS_HEX(*hex)) {
             if(ignore!=NULL && strchr(ignore,*hex)>0) {
                  ++hex;
                  ++hex_size;
                  continue;
             } else {
                  if(hex_end!=NULL) *hex_end=hex;
                  // finished scanning, exit.
                  break;
             }
        }
        if (bin_size >= bin_maxlen) {
            errno = ERANGE;
            return -1;
        }
        if(state == 0) {
            *result=TO_BIN(*hex) << 4;
            state = 1;
        } else {
            *result += TO_BIN(*hex);
            ++result; 
            state = 0; // New byte begin
            ++bin_size;
        }
        ++hex;
        ++hex_size;
    }
    // remaining hex does not compose a full byte.
    if(state != 0) {
        errno=EINVAL;
        return -1;
    }
    // the program do scan to the end but it does not match the hex_len input.
    if(hex_size != hex_len && hex_end==NULL) {
       errno=EINVAL;
       return -1;
    }
    *bin_len = bin_size;
    return 0;
}
#undef IS_HEX
#undef TO_BIN