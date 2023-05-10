void BN_free(BIGNUM *a)
{
    if (a == NULL)
        return;
    unsigned long flags = BN_get_flags(a, BN_FLG_STATIC_DATA);
    if (!flags)
        bn_free_d(a, 0);
    if (a->flags & BN_FLG_MALLOCED)
        OPENSSL_free(a);
}