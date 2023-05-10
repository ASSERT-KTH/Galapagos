void BN_free(BIGNUM *a)
{
    if (a == NULL)
        return;
    if (a->flags & BN_FLG_MALLOCED) {
        if (!BN_get_flags(a, BN_FLG_STATIC_DATA))
            bn_free_d(a, 0);
        OPENSSL_free(a);
    } else {
        if (!BN_get_flags(a, BN_FLG_STATIC_DATA))
            bn_free_d(a, 0);
    }
}