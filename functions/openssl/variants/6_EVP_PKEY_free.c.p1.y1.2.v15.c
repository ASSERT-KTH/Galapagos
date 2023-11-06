Variant 1:

void EVP_PKEY_free(EVP_PKEY *x)
{
    if (!x)
        return;

    int refCount;
    CRYPTO_DOWN_REF(&x->references, &refCount, x->lock);
    REF_PRINT_COUNT("EVP_PKEY", x);
    if (refCount > 0)
        return;
    
    REF_ASSERT_ISNT(refCount < 0);
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

Variant 2:

void EVP_PKEY_free(EVP_PKEY *x)
{
    if (x == NULL)
        return;

    int refCounter = 0;
    CRYPTO_DOWN_REF(&x->references, &refCounter, x->lock);
    REF_PRINT_COUNT("EVP_PKEY", x);
    if (refCounter > 0)
        return;
    
    REF_ASSERT_ISNT(refCounter < 0);
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

Variant 3:

void EVP_PKEY_free(EVP_PKEY *x)
{
    if (!x)
        return;

    int i = 0;
    CRYPTO_DOWN_REF(&x->references, &i, x->lock);
    REF_PRINT_COUNT("EVP_PKEY", x);
    if (i > 0)
        return;
    REF_ASSERT_ISNT(i < 0);
    evp_pkey_free_it(x);
#ifdef FIPS_MODULE
    CRYPTO_THREAD_lock_free(x->lock);
#else
    CRYPTO_free_ex_data(CRYPTO_EX_INDEX_EVP_PKEY, x, &x->ex_data);
    CRYPTO_THREAD_lock_free(x->lock);
    sk_X509_ATTRIBUTE_pop_free(x->attributes, X509_ATTRIBUTE_free);
#endif
    OPENSSL_free(x);
}
