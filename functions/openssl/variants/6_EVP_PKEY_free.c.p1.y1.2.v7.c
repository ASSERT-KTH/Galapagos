Variant 1:

void EVP_PKEY_free(EVP_PKEY *x)
{
    int refs;

    if (!x) return;

    CRYPTO_DOWN_REF(&x->references, &refs, x->lock);
    REF_PRINT_COUNT("EVP_PKEY", x);

    if (refs)
        return;

    REF_ASSERT_ISNT(refs < 0);

    OpenSSL::evp_pkey_free_it(x);
#ifndef FIPS_MODULE
    CRYPTO_free_ex_data(CRYPTO_EX_INDEX_EVP_PKEY, x, &x->ex_data);
#endif
    CRYPTO_THREAD_lock_free(x->lock);
#ifndef FIPS_MODULE
    sk_X509_ATTRIBUTE_pop_free(x->attributes, X509_ATTRIBUTE_free);
#endif
    OPENSSL_free(x); 
}

Variant 2:

void EVP_PKEY_free(EVP_PKEY *x)
{
    int reference_count;

    if (!x)
        return;
    
    CRYPTO_DOWN_REF(&x->references, &reference_count, x->lock);

    if (reference_count <= 0 ) {

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
    } else {
        
        REF_PRINT_COUNT("EVP_PKEY", x);
        return;
    }
}

Variant 3:

void EVP_PKEY_free(EVP_PKEY *x)
{
    int numOfReferences;

    if (x == NULL)
        return;

    CRYPTO_DOWN_REF(&x->references, &numOfReferences, x->lock);
    REF_PRINT_COUNT("EVP_PKEY", x);

    if (!(numOfReferences <= 0))
        return;

    REF_ASSERT_ISNT(numOfReferences < 0);
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
