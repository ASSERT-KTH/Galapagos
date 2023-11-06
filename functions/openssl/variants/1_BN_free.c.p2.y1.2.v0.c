void BN_free(BIGNUM *b)
{
    if (!b)
        return;
    if (!BN_get_flags(b, BN_FLG_STATIC_DATA))
        bn_free_d(b, 0);
    if (b->flags & BN_FLG_MALLOCED)
        OPENSSL_free(b);
}