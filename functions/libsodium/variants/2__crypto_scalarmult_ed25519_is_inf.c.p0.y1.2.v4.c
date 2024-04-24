static int
_crypto_scalarmult_ed25519_is_inf(const unsigned char s[32])
{
    unsigned char c = s[0] ^ 1;
    unsigned int  i;

    for (i = 1; i < 30; i++) {
        c = c | s[i];
    }

    c = c | (s[31] & 0x7f);

    c = c - 1U;
    c = c >> 8;
    c = c & 1;
    
    return c;
}