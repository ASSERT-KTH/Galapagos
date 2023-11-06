The following code is an alternative implementation of the `sodium_hex2bin` function:


int sodium_hex2bin(unsigned char *const bin, const size_t bin_maxlen,
                   const char *const hex, const size_t hex_len,
                   const char *const ignore, size_t *const bin_len,
                   const char **const hex_end) 
{
    size_t i, j = 0;
    int upper_nibble = 1;
    int nibble_value;
     
    for (i = 0; i < hex_len; ++i) {
        char c = hex[i];
        
        // Check each hexadecimal
        if (c >= '0' && c <= '9') nibble_value = c - '0';
        else if (c >= 'a' && c <= 'f') nibble_value = c - 'a' + 10;
        else if (c >= 'A' && c <= 'F') nibble_value = c - 'A' + 10;
        else if (ignore && strchr(ignore, c) != NULL) continue;
        else break; // Invalid character

        // Arrange the binary result
        if (upper_nibble) 
        {
            if (j >= bin_maxlen) 
            {
                errno = ERANGE;
                return -1;
            }
            bin[j] = nibble_value << 4;
        } 
        else bin[j++] |= nibble_value;
        
        upper_nibble = !upper_nibble;
    }

    // Return if input string was not an even length
    if (!upper_nibble) 
    {
        errno = EINVAL;
        return -1;
    }

    if (bin_len != NULL) *bin_len = j;

    // Mark where the conversion ended
    if (hex_end != NULL) *hex_end = &hex[i];
    else if (hex[i] != '\0') 
    {
        errno = EINVAL;
        return -1;
    }

    return 0;
}    

In this substitute implementation, the code checks each byte to see if it's valid. If the byte is a valid hexadecimal digit, it converts the byte to its corresponding value and stores this in the output buffer. If the byte is listed in the ignore string or is not a valid hexadecimal digit, the code ends the conversion. If the input string was not an even length, an error is returned. This implementation makes fewer comparisons and may annotate easier to understand. It works in a similar manner to the reference code and provides the same functionality. It asks if the character is a number, lowercase letter, or uppercase letter, creating the valid binary sequence.