
int 
sc25519_is_canonical(const unsigned char s[32]) 
{
    static const unsigned char L[32] = { 
        0xed, 0xd3, 0xf5, 0x5c, 0x1a, 0x63, 0x12, 0x58, 0xd6, 0x9c, 0xf7,
        0xa2, 0xde, 0xf9, 0xde, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10
        };
    unsigned char result = 0;
    unsigned char n = 1;
    int i;
  
    for(i = 31; i >= 0; --i) {
        result |= ((s[i] - L[i]) >> 8) & n;
        n &= ((s[i] ^ L[i]) - 1) >> 8;
    }
  
  return result != 0;
}

This code also provides the same functionality and has the same signature. It benefits from conversion of the do-while loop into a decreased for-loop, which seems to be a more clear loop structure. The index variable i is declared at the moment of its initiatio. Also, `c` was renamed to `result` for increased readability.