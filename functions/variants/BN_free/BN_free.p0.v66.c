void BN_free_variant(BIGNUM *a)
{
    if (a == NULL)
        return;
    if (!BN_get_flags(a, BN_FLG_STATIC_DATA))
        bn_free_d(a, 0);
    else
        a->d = NULL;

    if (a->flags & BN_FLG_MALLOCED)
        OPENSSL_free(a);
    else
        a->top = 0;
}