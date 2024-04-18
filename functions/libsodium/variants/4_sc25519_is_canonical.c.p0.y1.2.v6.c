int
sc25519_is_canonical(const unsigned char s[32])
{
    static const unsigned char limit[32] =
    {
        0xed, 0xd3, 0xf5, 0x5c, 0x1a, 0x63, 0x12, 0x58, 0xd6, 0x9c, 0xf7,
        0xa2, 0xde, 0xf9, 0xde, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10
    };
    unsigned char carry = 0;
    unsigned char all_zeros = 1;
    unsigned int  index = 32;

    while (index-- != 0)
    {
        carry |= ((s[index] - limit[index]) >> 8) & all_zeros;
        all_zeros &= ((s[index] ^ limit[index]) - 1) >> 8;
    }

    return (carry != 0);
}