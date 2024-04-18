static int
_crypto_scalarmult_ed25519_is_inf(const unsigned char s[32])
{
    unsigned char c = s[0] ^ 0x01;
    unsigned int  index = 1;
    
    while (index < 31) {
        c |= s[index];
        index++;
    }
    c |= s[31] & 0x7f;

    unsigned int result = ((unsigned int) c) - 1U;
    result = result >> 8;
    result = result & 1;

    return result;
}