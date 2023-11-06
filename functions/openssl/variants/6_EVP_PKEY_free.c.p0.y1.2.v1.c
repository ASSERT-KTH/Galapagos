void EVP_PKEY_free(EVP_PKEY *ptr)
{
    if (ptr != NULL) 
    {
        int refCount;
        
        CRYPTO_DOWN_REF(&(ptr->references), &refCount, ptr->lock);
        REF_PRINT_COUNT("EVP_PKEY", ptr);

        if (refCount > 0)
        {
            return;
        }

        REF_ASSERT_ISNT(refCount < 0);
        evp_pkey_free_it(ptr);

#ifndef FIPS_MODULE
        CRYPTO_free_ex_data(CRYPTO_EX_INDEX_EVP_PKEY, ptr, &(ptr->ex_data));
#endif

        CRYPTO_THREAD_lock_free(ptr->lock);

#ifndef FIPS_MODULE
        sk_X509_ATTRIBUTE_pop_free(ptr->attributes, X509_ATTRIBUTE_free);
#endif
        OPENSSL_free(ptr);
    }
}
