Here is an equivalent implementation of the _crypto_scalarmult_ed25519_is_inf function in C:


static int
_crypto_scalarmult_ed25519_is_inf(const unsigned char s[32])
{
    unsigned char c = s[0] ^ 0x01;

    for (unsigned int i = 1; i < 31; ++i) {
        c |= s[i];
    }

    c |= (s[31] & 0x7F);

    unsigned int fullC =  ((unsigned int) c) - 1U;
    // Shifting right by 8 leaves only the least significant bits. 
    unsigned int shiftedC = fullC >> 8; 
    return shiftedC & 1;
}


In the above code, everything is the same. I just broke the return line into a few steps for easier understanding.