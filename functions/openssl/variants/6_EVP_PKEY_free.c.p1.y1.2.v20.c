Variant 1:

void EVP_PKEY_free(EVP_PKEY *x)
{
    int refCounter;
    if (!x) return;

    CRYPTO_DOWN_REF(&(x->references), &refCounter, x->lock);
    REF_PRINT_COUNT("EVP_PKEY", x);
    if (refCounter > 0) return;

    REF_ASSERT_ISNT(refCounter < 0);

    evp_pkey_free_it(x);

#ifndef FIPS_MODULE
    CRYPTO_free_ex_data(CRYPTO_EX_INDEX_EVP_PKEY, x, &(x->ex_data));
    sk_X509_ATTRIBUTE_pop_free(x->attributes, X509_ATTRIBUTE_free);
#endif

    CRYPTO_THREAD_lock_free(x->lock);
    OPENSSL_free(x);
}

Variant 2:

void EVP_PKEY_free(EVP_PKEY *x)
{
    int ref_count;

    if(x != NULL)
    {
        CRYPTO_DOWN_REF(&x->references, &ref_count, x->lock);
        REF_PRINT_COUNT("EVP_PKEY", x);
        
        if (ref_count <= 0)
        {
            REF_ASSERT_ISNT(ref_count < 0);
            evp_pkey_free_it(x);

#ifndef FIPS_MODULE
            CRYPTO_free_ex_data(CRYPTO_EX_INDEX_EVP_PKEY, x, &x->ex_data);
            sk_X509_ATTRIBUTE_pop_free(x->attributes, X509_ATTRIBUTE_free);
#endif
      
            CRYPTO_THREAD_lock_free(x->lock);
            OPENSSL_free(x);
        }
    }
}

Variant 3:

void EVP_PKEY_free(EVP_PKEY *x)
{
    int i;

    if (x != NULL){
        CRYPTO_DOWN_REF(&x->references, &i, x->lock);
        REF_PRINT_COUNT("EVP_PKEY", x);
        
        if(i <= 0){
            REF_ASSERT_ISNT(i < 0);
            evp_pkey_free_it(x);

#ifndef FIPS_MODULE
            CRYPTO_free_ex_data(CRYPTO_EX_INDEX_EVP_PKEY, x, &x->ex_data);
            sk_X509_ATTRIBUTE_pop_free(x->attributes, X509_ATTRIBUTE_free);
#endif
            CRYPTO_THREAD_lock_free(x->lock);
            OPENSSL_free(x);
        }
    }     
}
