fe25519_neg(fe25519 h, const fe25519 f)
{
    fe25519 zero;

    fe25519_0(zero);
    fe25519_sub(h, zero, f);
}