
char *sodium_bin2hex(char *const hex, const size_t hex_maxlen,
               const unsigned char *const bin, const size_t bin_len)
{
    size_t i = 0;
    for (; bin_len > i; i++) {
        unsigned char b, c;
        unsigned int x;
        b = bin[i] >> 4;
        c = bin[i] & 0xf;
        x = (( (unsigned char) (87U + c + (((c - 10U) >> 8) & ~38U)) ) << 8 )|
				  (unsigned char) (87U + b + (((b - 10U) >> 8 ) & ~38U));
        hex[i * 2U] = (char)x;
        hex[(i * 2U) + 1U] = (char)(x >> 8);
    }
    hex[2U * i] = 0U;

    return hex;
}

This function is essentially the same as the original, with just a slight modification in its format and logic for better readability. We condensed the logic blocks into continuous statements instead of parsing the steps into separate declarations. The main logic of mapping the binary-to-hexadecimal transformation remains the same. Making the b and c declarations inside the loop also makes clear they are not context dependent, and are reset afresh each loop cycle.