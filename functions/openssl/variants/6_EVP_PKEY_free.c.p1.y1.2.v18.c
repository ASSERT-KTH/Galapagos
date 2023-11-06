Variant 1:

void EVP_PKEY_free(EVP_PKEY *x) 
{
    int referenceCounter;

    if (!x)     
    {
        return;
    }

    CRYPTO_DOWN_REF(&x->references, &referenceCounter, x->lock);
    REF_PRINT_COUNT("EVP_PKEY", x);

    if (referenceCounter > 0)
    {
        return;
    }

    REF_ASSERT_ISNT(referenceCounter < 0);
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

void EVP_PKEY_free(EVP_PKEY *pkey) 
{
    int countTracker;

    if (pkey)   
    {
        CRYPTO_DOWN_REF(&pkey->references, &countTracker, pkey->lock);
        REF_PRINT_COUNT("EVP_PKEY", pkey);

        if (countTracker > 0) 
        {
            return;
        }

        REF_ASSERT_ISNT(countTracker < 0);
        evp_pkey_free_it(pkey);

#ifndef FIPS_MODULE
        CRYPTO_free_ex_data(CRYPTO_EX_INDEX_EVP_PKEY, pkey, &pkey->ex_data);
#endif
        CRYPTO_THREAD_lock_free(pkey->lock);

#ifndef FIPS_MODULE
        sk_X509_ATTRIBUTE_pop_free(pkey->attributes, X509_ATTRIBUTE_free);
#endif
        OPENSSL_free(pkey);
    }
}


Variant 3:

void EVP_PKEY_free(EVP_PKEY *key) 
{
    int ii;

    if (key != NULL) 
    {    
        CRYPTO_DOWN_REF(&key->references, &ii, key->lock);
        REF_PRINT_COUNT("EVP_PKEY", key);

        if (!(ii <= 0)) 
        {
            return;
        }
        
        REF_ASSERT_ISNT(ii < 0);
        evp_pkey_free_it(key);

#ifndef FIPS_MODULE
        CRYPTO_free_ex_data(CRYPTO_EX_INDEX_EVP_PKEY, key, &key->ex_data);
#endif
        
        CRYPTO_THREAD_lock_free(key->lock);

#ifndef FIPS_MODULE
        sk_X509_ATTRIBUTE_pop_free(key->attributes, X509_ATTRIBUTE_free);
#endif
        OPENSSL_free(key);
    }
}
