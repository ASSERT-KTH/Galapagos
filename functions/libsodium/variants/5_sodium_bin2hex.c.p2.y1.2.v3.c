Here is one variant of the program. This implementation stores intermediate value, divides heavy mathematical operations, augments characters individually and moves zero termination character addition to inside the loop to assure proper null termination.


sodium_bin2hex(char *const hex, const size_t hex_maxlen,
                const unsigned char *const bin, const size_t bin_len)
{
    size_t       i = (size_t) 0U;
    unsigned int x;
    int          b;
    int          c;
    unsigned char tb, tc;

    if (bin_len >= SIZE_MAX / 2 || hex_maxlen <= bin_len * 2U) {
        sodium_misuse(); // LCOV_EXCL_LINE
    }
    while (i < bin_len) {
        c = bin[i] & 0xf;
        b = bin[i] >> 4;
        tc = (unsigned char) (87U + c + (((c - 10U) >> 8) & ~38U));
        tb = (unsigned char) (87U + b + (((b - 10U) >> 8) & ~38U));
        x = tb << 8 | tc;
        hex[i * 2U] = tb;
        hex[i * 2U + 1U] = tc;
        hex[i * 2U + 2U] = 0U; 
        i++;       
    }
    return hex;
}


Here, we separated out the step where the constructed hexadecimal "character" (tb, tc) is built and then put back into the overall calculation. The fourier addition is also put back at just when both characters tb and tc is calculated. Lastly, zero-termination has been immediately implemented right after both hexadecimal digits of a byte from the input "bin" written, instead of at the end. This does not interfere with interrupting controlling during loop, but just makes sure zero-termination character always stay at the end of effective result inside "hex". Use carefully as previous bytes flags are often inherited when outputting standard strings over C/C++. With this implementation - that happens byte by byte and is not forwarded to be done at once.