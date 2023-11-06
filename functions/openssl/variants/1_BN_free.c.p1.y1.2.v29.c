# Variant 1 - Single return pattern

void BN_free(BIGNUM *a)
{
    if (a != NULL)
    {
        if (!BN_get_flags(a, BN_FLG_STATIC_DATA))
            bn_free_d(a, 0);

        if (a->flags & BN_FLG_MALLOCED)
            OPENSSL_free(a);
    }
}

# Variant 2 - Early return alignment

void BN_free(BIGNUM *a)
{
    if (a == NULL)
        return;

    if (BN_get_flags(a, BN_FLG_STATIC_DATA) == 0)
        bn_free_d(a, 0);
        
    if (a->flags & BN_FLG_MALLOCED)
        OPENSSL_free(a);
}

# Variant 3 - Flag logical expressions adjustment 

void BN_free(BIGNUM *a)
{
    if(!a)
        return;

    if (!(BN_get_flags(a, BN_FLG_STATIC_DATA)))
        bn_free_d(a, 0);

   if (a->flags & BN_FLG_MALLOCED)
       OPENSSL_free(a);

}

# Variant 4 - Extended FlG evaluation

void BN_free(BIGNUM *a)
{
    if (a != NULL)
    {
        if (BN_get_flags(a, BN_FLG_STATIC_DATA)==0)
            bn_free_d(a, 0);

        if ((a->flags & BN_FLG_MALLOCED)!=0)
            OPENSSL_free(a);
    }
}