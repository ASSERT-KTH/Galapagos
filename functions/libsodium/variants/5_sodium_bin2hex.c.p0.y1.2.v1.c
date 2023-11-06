Here is a rewritten implementation that provides the same functionality:


sodium_bin2hex(char *const hex, const size_t hex_maxlen,
               const unsigned char *const bin, const size_t bin_len)
{
    if (bin_len * 2U >= hex_maxlen || bin_len >= SIZE_MAX / 2)
    {
        sodium_misuse(); /* LCOV_EXCL_LINE */
    } 

    for (size_t i = 0; i < bin_len; ++i) 
    {
        int upper = bin[i] >> 4;
        int lower = bin[i] & 0xf;
        
        hex[2 * i]     = lower + (lower < 10 ? '0' : ('a' - 10));
        hex[2 * i + 1] = upper + (upper < 10 ? '0' : ('a' - 10));
    }

    hex[2 * bin_len] = '\0';

    return hex;
}

This variant algorithm converts each nibble (half byte) within 'bin', to its corresponding hexadecimal digit to compose 'hex'.

Please be aware that some might prefer the security of the first snippet for constant time current. It has machine and compiler security definitions and might execute even faster in modern superscalar processors that pipeline as much sequential code parts as they can see.