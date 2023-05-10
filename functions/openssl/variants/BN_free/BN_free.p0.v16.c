void BN_free(BIGNUM *a)
{
    if (!a)
        return;
    if ((a->flags & BN_FLG_STATIC_DATA) == 0)
        bn_free_d(a, 0);
    if (a->flags & BN_FLG_MALLOCED)
        OPENSSL_free(a);
}