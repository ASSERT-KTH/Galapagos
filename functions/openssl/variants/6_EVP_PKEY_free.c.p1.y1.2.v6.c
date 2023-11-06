Variant 1:

void EVP_PKEY_free(EVP_PKEY *x)
{
    int i;
    if (x)
    {
        CRYPTO_DOWN_REF(&x->references, &i, x->lock);
        if(i <= 0)
        {
            REF_PRINT_COUNT("EVP_PKEY", x);
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
    else
        return;
}

Variant 2:

void EVP_PKEY_free(EVP_PKEY *x)
{
    if (!x)
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

Variant 3:

void EVP_PKEY_free(EVP_PKEY *x)
{
    if (x == NULL)
        return;

    int i;
    CRYPTO_DOWN_REF(&x->references, &i, x->lock);
    
    REF_PRINT_COUNT("EVP_PKEY", x);
    if (i <= 0)
    {
#ifndef FIPS_MODULE
        evp_pkey_free_it(x);
        CRYPTO_free_ex_data(CRYPTO_EX_INDEX_EVP_PKEY, x, &x->ex_data);
        CRYPTO_THREAD_lock_free(x->lock);
        sk_X509_ATTRIBUTE_pop_free(x->attributes, X509_ATTRIBUTE_free);
#endif

#ifndef FIPS_MODULE
        OPENSSL_free(x);
#endif
    }
    REF_ASSERT_ISNT(i < 0); 
}
