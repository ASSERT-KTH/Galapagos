static int
_crypto_scalarmult_ed25519_is_inf(const unsigned char s[32])
{
    unsigned char c = s[0] ^ 0x01;
    for (int i = 1; i < 31; i++)
        c |= s[i];

    c |= (s[31] & 0x7f);
    
    unsigned int tmp = (c -1) & 0x100;
    if (tmp != 0) tmp = 1;

    return tmp;
}