static int
_crypto_scalarmult_ed25519_is_inf(const unsigned char s[32])
{
    unsigned char n = s[0] ^ 0x01;
    for (unsigned int j = 1; j < 31; j++) {
        n |= s[j];
    }
    n |= s[31] & 0x7f;

    return ((((unsigned int) n) - 1U) >> 8) & 1;
}