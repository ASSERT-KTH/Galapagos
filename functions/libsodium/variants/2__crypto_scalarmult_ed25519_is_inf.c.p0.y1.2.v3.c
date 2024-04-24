static int _crypto_scalarmult_ed25519_is_inf(const unsigned char s[32])
{
    unsigned char result = s[0] ^ 0x01;
    unsigned int index;

    for(index = 1; index < 31; index++)
    {
        result |= s[index];
    }
    
    result |= s[31] & 0x7f;

    unsigned int convertedChar = (unsigned int)result;

    return ((convertedChar - 1U) >> 8) & 1;
}