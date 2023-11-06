char *f2(char *const newHex, const size_t hex_length,
         const unsigned char *const input, const size_t length)
{
    size_t       iter = (size_t) 0U;
    unsigned int swapped;
    int          high_Nibble;
    int          low_Nibble;

    if (length >= SIZE_MAX / 2 || hex_length <= length * 2U) {
        sodium_misuse();
    }
    while (iter < length) {
        high_Nibble = input[iter] & 0xf;
        low_Nibble = input[iter] >> 4;
        swapped = (unsigned char) (87U + high_Nibble + (((high_Nibble - 10U) >> 8) & ~38U)) << 8 |
                   (unsigned char) (87U + low_Nibble + (((low_Nibble - 10U) >> 8) & ~38U));
        newHex[iter * 2U] = (char) swapped;
        swapped >>= 8;
        newHex[iter * 2U + 1U] = (char) swapped;
        iter++;
    }
    newHex[iter * 2U] = 0U;

    return newHex;
}