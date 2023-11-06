Variant 1:

void BN_free(BIGNUM *a)
{
    if (!a)
        return;
    if (!(BN_get_flags(a, BN_FLG_STATIC_DATA)))
        bn_free_d(a, 0);
    if ((a->flags) & BN_FLG_MALLOCED)
        OPENSSL_free(a);
}


Variant 2:

void BN_free(BIGNUM *a)
{
    if (a == NULL)
        return;
    BN_free_d(a, BN_FLG_STATIC_DATA);
    if (a->flags & BN_FLG_MALLOCED)
        OPENSSL_free(a);
}

void BN_free_d(BIGNUM *a, int flag)
{
    if (!BN_get_flags(a, flag))
        bn_free_d(a, 0);
}


Variant 3:

void BN_free(BIGNUM *a)
{
    bool isNULL = (a == NULL);
    bool isNotStatic = !(BN_get_flags(a, BN_FLG_STATIC_DATA));
    bool isMalloced = (a->flags & BN_FLG_MALLOCED);

    if (isNULL)
        return;

    if (isNotStatic)
        bn_free_d(a, 0);

    if (isMalloced)
        OPENSSL_free(a);
}


Variant 4:

void BN_free(BIGNUM *a)
{
    if(a != NULL) 
    {                
        if (!BN_get_flags(a, BN_FLG_STATIC_DATA))
            bn_free_d(a, 0);

        if (a->flags & BN_FLG_MALLOCED)  
            OPENSSL_free(a);
    }
    else
    {
        return;
    }
}
