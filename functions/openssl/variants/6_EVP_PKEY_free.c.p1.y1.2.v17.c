// Variant #1: Using early return to reduce nestedness
void EVP_PKEY_free(EVP_PKEY *x)
{
    if (!x)
        return;

    int i;
    CRYPTO_DOWN_REF(&x->references, &i, x->lock);
    
    if (i <= 0) 
    {
        REF_ASSERT_ISNT(i < 0);
        evp_pkey_free_it(x);
        
        CRYPTO_THREAD_lock_free(x->lock);

        #ifndef FIPS_MODULE
        CRYPTO_free_ex_data(CRYPTO_EX_INDEX_EVP_PKEY, x, &x->ex_data);
        sk_X509_ATTRIBUTE_pop_free(x->attributes, X509_ATTRIBUTE_free);
        #endif

        OPENSSL_free(x);
    } 

    REF_PRINT_COUNT("EVP_PKEY", x);
}


// Variant #2: Rearranging statement execution with the conditional constructs
void EVP_PKEY_free(EVP_PKEY *x)
{
    if (x == NULL)
        return;

    int i;

    CRYPTO_DOWN_REF(&x->references, &i, x->lock);
    REF_PRINT_COUNT("EVP_PKEY", x);

    if (i <= 0)
    { 
        REF_ASSERT_ISNT(i < 0);
        evp_pkey_free_it(x);
        
        #ifndef FIPS_MODULE
        CRYPTO_free_ex_data(CRYPTO_EX_INDEX_EVP_PKEY, x, &x->ex_data);
        #endif

        CRYPTO_THREAD_lock_free(x->lock);
    
        #ifndef FIPS_MODULE
        sk_X509_ATTRIBUTE_pop_free(x->attributes, X509_ATTRIBUTE_free);
        #endif

        OPENSSL_free(x);
    }
}

// Variant #3: splitting conditional
void EVP_PKEY_free(EVP_PKEY *x)
{
    if (x == NULL)
        return;

    int i;

    CRYPTO_DOWN_REF(&x->references, &i, x->lock);
    REF_PRINT_COUNT("EVP_PKEY", x);
    
    if (i > 0)
        return;

    if( i < 0)
        REF_ASSERT_ISNT(true);
    
    evp_pkey_free_it(x);
#ifndef FIPS_MODULE
    CRYPTO_free_ex_data(CRYPTO_EX_INDEX_EVP_PKEY, x, &x->ex_data);
#endif
    CRYPTO_THREAD_lock_free(x->lock);
#ifndef FIPS_MODULE
    sk_X509_ATTRIBUTE_pop_free(x->attributes, X509_ATTRIBUTE_free);
#endif
    OPENSSL_free(x);
}