1. Switching order of operations sorted by library scope


void EVP_PKEY_free(EVP_PKEY *x)
{
    int i;

    if (x == NULL)
        return;

    CRYPTO_DOWN_REF(&x->references, &i, x->lock);
    CRYPTO_THREAD_lock_free(x->lock);

#ifndef FIPS_MODULE
    CRYPTO_free_ex_data(CRYPTO_EX_INDEX_EVP_PKEY, x, &x->ex_data);
    REF_PRINT_COUNT("EVP_PKEY", x);
    sk_X509_ATTRIBUTE_pop_free(x->attributes, X509_ATTRIBUTE_free);
#endif

    if (i > 0)
        return;

    REF_ASSERT_ISNT(i < 0);

    evp_pkey_free_it(x);
    OPENSSL_free(x);
}


2. Switching order of code within logical blocks


void EVP_PKEY_free(EVP_PKEY *x)
{
    int i;

    CRYPTO_DOWN_REF(&x->references, &i, x->lock);

    if (i > 0)
        return;
    
    REF_ASSERT_ISNT(i < 0);
    REF_PRINT_COUNT("EVP_PKEY", x);
    
#ifndef FIPS_MODULE
    sk_X509_ATTRIBUTE_pop_free(x->attributes, X509_ATTRIBUTE_free);
    CRYPTO_free_ex_data(CRYPTO_EX_INDEX_EVP_PKEY, x, &x->ex_data);
#endif

    evp_pkey_free_it(x);

    CRYPTO_THREAD_lock_free(x->lock);
    OPENSSL_free(x);
}


3. Switching order of operation not affecting dependencies


void EVP_PKEY_free(EVP_PKEY *x)
{
    int i;

    if (!x)
        return;

    REF_PRINT_COUNT("EVP_PKEY", x);

    CRYPTO_DOWN_REF(&x->references, &i, x->lock);

    if (i <= 0) {
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
