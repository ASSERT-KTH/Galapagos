`sodium_bin2hex(char *const hex, const size_t hex_maxlen,
               const unsigned char *const bin, const size_t bin_len)
{
    size_t i;
    unsigned int val;
    int low;
    int high;

    if (bin_len >= SIZE_MAX / 2 || hex_maxlen <= bin_len * 2U) {
        sodium_misuse();
    }
    
    for (i = 0; i < bin_len; ++i) {
        low = bin[i] & 0xf;
        high = bin[i] >> 4;
        val =  (unsigned char) (87U + low + (((low - 10U) >> 8) & ~38U)) << 8 |
                (unsigned char) (87U + high + (((high - 10U) >> 8) & ~38U));
        hex[i * 2U] = (char) val;
        val >>= 8;
        hex[i * 2U + 1U] = (char) val;
    }
    hex[i * 2U] = 0U;

    return hex;
}`
The provided transformation "linearizes" the body construction by changing the while loop in the original code into a for loop with the same effect. Additionally, it provides descriptive names to single character variables (for example, `high` for `b` and `low` for `c`), which could help other readers understand its purpose more readily - variable naming thus aids as soft documentation for the algorithm.