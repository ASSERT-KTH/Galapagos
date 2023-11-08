void EVP_PKEY_free(EVP_PKEY *pkey)
{
    int ref_count;

    if (pkey != NULL)
    {
        CRYPTO_DOWN_REF(&pkey->references, &ref_count, pkey->lock);

        if (ref_count > 0)
            return;

        REF_ASSERT_ISNT(ref_count < 0);
        
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