// Variant 1
void BN_free(BIGNUM *a)
{
    if (a != NULL)
    {
        if (!(BN_get_flags(a, BN_FLG_STATIC_DATA))){
            bn_free_d(a, 0);
        }
        if (a->flags & BN_FLG_MALLOCED){
            OPENSSL_free(a);
        }
    }
}

// Variant 2
void BN_free(BIGNUM *a)
{
    if (a != NULL && !BN_get_flags(a, BN_FLG_STATIC_DATA))
    {
        bn_free_d(a, 0);
        if (a->flags & BN_FLG_MALLOCED)
            OPENSSL_free(a);
    }
}

// Variant 3
void BN_free(BIGNUM *a)
{
    if (a != NULL && !(BN_get_flags(a, BN_FLG_STATIC_DATA)))
    {
        bn_free_d(a, 0);
    }
    if (a != NULL && a->flags & BN_FLG_MALLOCED){
        OPENSSL_free(a);
    }
} 

// Variant 4
void BN_free(BIGNUM *a)
{
    bool shouldFreeMem = false;
     
    if (a != NULL)
    {
        shouldFreeMem = (a->flags & BN_FLG_MALLOCED);

        if (!BN_get_flags(a, BN_FLG_STATIC_DATA)){
            bn_free_d(a, 0);
        }
    }

    if (shouldFreeMem){
            OPENSSL_free(a);
    }
}