Variant A:

void BN_free(BIGNUM *a)
{
    if (!a)
        return;
    if (!BN_get_flags(a, BN_FLG_STATIC_DATA))
        bn_free_d(a, 0);
    if ((a->flags) & BN_FLG_MALLOCED)
        OPENSSL_free(a);
}


Variant B:

void BN_free(BIGNUM *a)
{
    if (a != NULL) {
        if (!BN_get_flags(a, BN_FLG_STATIC_DATA))
            bn_free_d(a, 0);
        if (a->flags & BN_FLG_MALLOCED)
            OPENSSL_free(a);
    }
}


Variant C:

void BN_free(BIGNUM *a)
{
    if (!a)
        return;
    if (!BN_get_flags(a, BN_FLG_STATIC_DATA))
        bn_free_d(a, 0);
    if (a->flags & BN_FLG_MALLOCED) {
        OPENSSL_free(a);
    }
}


Variant D:

void BN_free(BIGNUM *a)
{
    if (a == NULL)
        return;
    if (!BN_get_flags(a, BN_FLG_STATIC_DATA)) {
        bn_free_d(a, 0);
    } 
    if (a->flags & BN_FLG_MALLOCED)
        OPENSSL_free(a);
}
 

Variant E:

void BN_free(BIGNUM *a)
{
    if ((a == NULL))
        return;
    if (!(BN_get_flags(a, BN_FLG_STATIC_DATA)))
        bn_free_d(a, 0);
    if ((a->flags & BN_FLG_MALLOCED))
        OPENSSL_free(a);
}
