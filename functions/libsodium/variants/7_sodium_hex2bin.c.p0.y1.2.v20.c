#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int sodium_hex2bin(unsigned char *const bin, const size_t bin_maxlen, 
                   const char *const hex, const size_t hex_len,
                   const char *const ignore, size_t *const bin_len,
                   const char **const hex_end){
                   
    size_t bin_i = 0;
    size_t hex_i = 0;
    
    int freshData = 1;
    int r = 0;
    
    if(hex_end != NULL){
        *hex_end = hex;
    }

    for(; hex_i < hex_len; hex_i++){
        unsigned char current = (unsigned char) hex[hex_i];
        unsigned char decoded = 0;

        if(ignore != NULL && strchr(ignore, current) != NULL){
           continue;
        }
        if(current >= '0' && current <= '9'){
            decoded = current -'0';
        } else if(current >= 'A' && current <='F'){
            decoded = current -'A'+10;
        } else if(current >= 'a' && current <='f'){
            decoded = current -'a'+10;
        } else {
            r = -1;
            errno = EINVAL;
            return r;
        }
        
        if(bin_i >= bin_maxlen){
            r = -1;
            errno = ERANGE;
            return r;
        }
        
        if(freshData) {
            bin[bin_i] = decoded << 4;
            freshData = 0;
        } else {
            bin[bin_i] = bin[bin_i] | decoded;
            freshData = 1;
            bin_i++;
        }
        
    }
    
    if(!freshData){
        hex_i--;
    }

    if(bin_len != NULL){
        *bin_len = bin_i;
    }

    if(hex_end != NULL){
        *hex_end = &hex[hex_i];
    }

return r;
}