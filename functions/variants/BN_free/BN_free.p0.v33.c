void BN_free(BIGNUM *a)
{
    if (a == NULL)
        return;
    
    if (!(a->flags & BN_FLG_STATIC_DATA))
        bn_free_d(a, 0);
    
    if (a->flags & BN_FLG_MALLOCED)
        OPENSSL_free(a);
    else
        a = NULL;
}