Version 1:


void BN_free(BIGNUM *a)
{
    if (a == NULL)
    {
        return;
    }

    if (!(BN_get_flags(a, BN_FLG_STATIC_DATA)))
    {
        bn_free_d(a, 0);
    }
        
    if ((a->flags & BN_FLG_MALLOCED) != 0)
    {
        OPENSSL_free(a);
    }   
}


Version 2:


void BN_free(BIGNUM *a)
{
    if (a != NULL) 
    {
        if (!BN_get_flags(a, BN_FLG_STATIC_DATA))
        {
            bn_free_d(a, 0);
        }
        if ((a->flags & BN_FLG_MALLOCED))
        {
            OPENSSL_free(a);
        }  
    }
}


Version 3:


void BN_free(BIGNUM *a)
{
    if (a) 
    {
        if (BN_get_flags(a, BN_FLG_STATIC_DATA) == 0)
        {
            bn_free_d(a, 0);
        }
        if (a->flags & BN_FLG_MALLOCED)
        {
            OPENSSL_free(a);
        }
    }
}