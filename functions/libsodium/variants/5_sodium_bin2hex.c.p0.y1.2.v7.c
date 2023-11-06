Your new implementation could look like this:


sodium_bin2hex(char* const hex, const size_t hex_maxlen, 
               const unsigned char* const bin, const size_t bin_len) 
{   
    static const char *lookup = "0123456789abcdef";

    if (bin_len > (hex_maxlen - 1) / 2) {
        sodium_misuse();
    }
   
    size_t i;
    for (i = 0; i < bin_len; i++) {
        hex[i * 2] = lookup[(bin[i] >> 4) & 0xf];
        hex[i * 2 + 1] = lookup[bin[i] & 0xf];
    }
    hex[i * 2] = '\0';
    
    return hex;
}

This implementation uses binary manipulation and looks in a char-array to get the hexadecimal representation. 

The character-lookup approach negates the need for unusual mathematical expressions for handling the hexadecimal conversion.That in turn makes the newly coded function easier to understand and keeps the properties of the original implementation intact.