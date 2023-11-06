void BN_free(BIGNUM *a)
{
    if (!a)
        return;

    if (a->flags & BN_FLG_STATIC_DATA)
    {
        if (!bn_free_d(a, 0))
            return;
    }

    if (a->flags & BN_FLG_MALLOCED)
        OPENSSL_free(a);
}