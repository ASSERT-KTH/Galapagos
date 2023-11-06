void EVP_PKEY_free(EVP_PKEY *key)
{
    int ref_count;
    
    if (key != NULL) 
    {
        CRYPTO_DOWN_REF(&key->references, &ref_count, key->lock);

        if (ref_count > 0) 
        {
            return; 
        }
        assert(!(ref_count < 0));
        
        REF_PRINT_COUNT("EVP_PKEY", key);
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