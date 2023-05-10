void BN_free_alt1(BIGNUM *a)
{
    if (a == NULL)
    {
        return;
    }
    if (BN_get_flags(a, BN_FLG_STATIC_DATA) == 0)
    {
        bn_free_d(a, 0);
    }
    if (a->flags & BN_FLG_MALLOCED)
    {
        OPENSSL_free(a);
    }
}