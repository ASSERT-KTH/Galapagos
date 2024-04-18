Here's an equivalent function that should work in the same way as your original "_crypto_scalarmult_ed25519_is_inf" function, just with a small refactoring.


static int
_crypto_scalarmult_ed25519_is_inf(const unsigned char s[32])
{
    unsigned char c = s[0] ^ 0x01;

    for(int i = 1; i < 31; ++i) {
        c |= s[i];
    }

    c |= s[31] & 0x7f;

    unsigned int tmp = c;
    return (((tmp - 1U) >> 8) & 1);
}

This version performs same the operations while using new single expression for variable "i"++ and applying number precedence in last statement.