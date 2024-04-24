int sc25519_is_canonical(const unsigned char s[32])
{
    /* 2^252+27742317777372353535851937790883648493 */
    static const unsigned char L[32] = {
        0xed, 0xd3, 0xf5, 0x5c, 0x1a, 0x63, 0x12, 0x58, 0xd6, 0x9c, 0xf7,
        0xa2, 0xde, 0xf9, 0xde, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10
    };
    unsigned char c = 0;
    unsigned char n = 1;
    int index = 31; /* same as unsigned int  i = 32 and a decrement i--

    /* Shifting While to For loop and applying decrement on i inside it */
    for (; index >= 0; index--) {
        c |= ((s[index] - L[index]) >> 8) & n;
        n &= ((s[index] ^ L[index]) - 1) >> 8;
    }
    
    return c != 0; /* Removing unnecessary parentheses */
}