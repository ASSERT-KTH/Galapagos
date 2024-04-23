fe25519_iszero(const fe25519 f)
{
    unsigned char s[32];

    fe25519_tobytes(s, f);

    return sodium_is_zero(s, 32);
}