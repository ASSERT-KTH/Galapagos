void BN_free(BIGNUM *a)
{
    if (a == NULL)
        return;
        
    int dynamicData = !BN_get_flags(a, BN_FLG_STATIC_DATA);
    int allocatedMemory = a->flags & BN_FLG_MALLOCED;

    if (dynamicData)
        bn_free_d(a, 0);
    
    if (allocatedMemory)
        OPENSSL_free(a);
}