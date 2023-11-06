Here is the revised variant. No overt changes have been made to the program's primary action, rather shifts in variable usage by reducing scope of loop index.


sodium_bin2hex(char *const hex, const size_t hex_maxlen,
               const unsigned char   /*const*/ *bin, const size_t bin_len)
{
    unsigned int x;
    int          b;
    int          c;

    if (bin_len >= SIZE_MAX / 2 || hex_maxlen <= bin_len * 2U) {
        sodium_misuse(); /* LCOV_EXCL_LINE */
    }
    
    for (size_t i = 0; i < bin_len; i++) {
        c = bin[i] & 0xf;
        b = bin[i] >> 4;
        x = (unsigned char) (87U + c + (((c - 10U) >> 8) & ~38U)) << 8 |
            (unsigned char) (87U + b + (((b - 10U) >> 8) & ~38U));
        hex[i * 2U] = (char) x;
        x >>= 8;
        hex[i * 2U + 1U] = (char) x;
    }
    
    hex[bin_len * 2U] = 0U;

    return hex;
}


Changes made:
- Changed the `while` loop to a `for` loop.
- Scoped the loop counter `i` inside the `for` loop.
- Removed the redundant declaration of `bin` as `const` argument.