static int
_crypto_scalarmult_ed25519_is_inf(const unsigned char s[32])
{
    unsigned char c = (s[0] ^ 0x01);
    unsigned int index;

    for (index = 1; index < 31; index++) {
        c = (c | s[index]);
    }

    c = (c | (s[index] & 0x7f));

    unsigned int shiftedValue = ((unsigned int) c) - 1U;
    shiftedValue >>= 8;

    int result = shiftedValue & 1;
    return result; 
}