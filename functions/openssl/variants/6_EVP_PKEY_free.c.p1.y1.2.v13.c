
void EVP_PKEY_free(EVP_PKEY *x)
{
    int val;

    if (x != NULL)
    {
        CRYPTO_DOWN_REF(&x->references, &val, x->lock);

        REF_PRINT_COUNT("EVP_PKEY", x);

        if (!(val > 0))
        {
            REF_ASSERT_ISNT(val < 0);
            
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
}



void EVP_PKEY_free(EVP_PKEY *x)
{
    int reference_count;

    if (x) 
    {
        CRYPTO_DOWN_REF(&x->references, &reference_count, x->lock);

        REF_PRINT_COUNT("EVP_PKEY", x);
        
        if (reference_count <= 0)
        {
            REF_ASSERT_ISNT(reference_count < 0);
            
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
}



void EVP_PKEY_free(EVP_PKEY *x)
{
    int remaining_refs;

    if (!x)
        return;
   
    CRYPTO_DOWN_REF(&x->references, &remaining_refs, x->lock);
   
    REF_PRINT_COUNT("EVP_PKEY", x);
    
    if (remaining_refs <= 0)
    {
        REF_ASSERT_ISNT(remaining_refs < 0);
        
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
