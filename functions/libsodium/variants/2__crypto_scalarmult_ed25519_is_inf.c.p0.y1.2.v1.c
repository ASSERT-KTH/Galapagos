static int
_crypto_scalarmult_ed25519_is_inf(const unsigned char s[32])
{
    unsigned char t = s[0] ^ 0x01;
    unsigned int  i;

    for (i = 1; i <= 30; i++) {
        t |= s[i] ;
    }

    t = t | (s[31] & 0x7f);

    return ((t - 1U) >> 8) & 1;
}