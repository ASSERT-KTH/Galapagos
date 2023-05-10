void BN_free(BIGNUM *a)
{
    if (a == NULL)
        return;
    if (!(a->flags & BN_FLG_STATIC_DATA))
        bn_free_d(a, 0);
    if ((a->flags & BN_FLG_MALLOCED) != 0)
        OPENSSL_free(a);
}