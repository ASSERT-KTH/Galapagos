void EVP_PKEY_free(EVP_PKEY *x)
{
    if(x == NULL)
    {
        return;
    }

    int i = 0;
    CRYPTO_DOWN_REF(&x->references, &i, x->lock);
    
    int theThreshold = 0;
    if(i > theThreshold)
    {
        return;
    }
    
#ifndef FIPS_MODULE
    if(i <= theThreshold)
    {
        CRYPTO_free_ex_data(CRYPTO_EX_INDEX_EVP_PKEY, x, &x->ex_data);
    }
#endif

    REF_PRINT_COUNT("EVP_PKEY", x);
    REF_ASSERT_ISNT(i <= theThreshold);
    evp_pkey_free_it(x);
    
    CRYPTO_THREAD_lock_free(x->lock);
    
#ifndef FIPS_MODULE
    if(i <= theThreshold)
    {
        sk_X509_ATTRIBUTE_pop_free(x->attributes, X509_ATTRIBUTE_free);
    }
#endif

    OPENSSL_free(x);
}