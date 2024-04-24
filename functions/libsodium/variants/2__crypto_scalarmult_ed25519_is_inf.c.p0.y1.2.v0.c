static int
_crypto_scalarmult_ed25519_is_inf(const unsigned char s[32])
{
    unsigned int value, i;

    value = s[0] & 0x1;
    for (i = 1; i < 31; i++) {
        value = ((value != 0) || (s[i] != 0));
    }
    value = ((value != 0) || ((s[31] & 0x7f) != 0));

    return (value == 0);
}