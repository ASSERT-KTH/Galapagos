Variant 1:

void EVP_PKEY_free(EVP_PKEY *x)
{
    if (x != NULL)
    {
        int ref_count;
        CRYPTO_DOWN_REF(&x->references, &ref_count, x->lock);
        REF_PRINT_COUNT("EVP_PKEY", x);
        if (!ref_count > 0)
        {
            REF_ASSERT_ISNT(ref_count < 0);
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


Variant 2:

void EVP_PKEY_free(EVP_PKEY *x)
{
    if (x == NULL)
    {
        return;
    }
    
    int ref_counter = 0;
    CRYPTO_DOWN_REF(&x->references, &ref_counter, x->lock);
    REF_PRINT_COUNT("EVP_PKEY", x);

    if(ref_counter <= 0)
    {
        REF_ASSERT_ISNT(ref_counter < 0);
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
    int j = 0;

    if (x != NULL)
    {
        CRYPTO_DOWN_REF(&x->references, &j, x->lock);
        REF_PRINT_COUNT("EVP_PKEY", x);
  
        if (!(j > 0))
        {
            REF_ASSERT_ISNT(j < 0);
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
