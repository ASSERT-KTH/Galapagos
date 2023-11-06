void EVP_PKEY_free(EVP_PKEY *y)
{
    int j;

    if (y != NULL)
    {
        CRYPTO_DOWN_REF(&y->references, &j, y->lock);
        REF_PRINT_COUNT("EVP_PKEY", y);
        if (j <= 0) 
        {
            if (j < 0) 
                REF_ASSERT_ISNT(1);
            else {    
                evp_pkey_free_it(y);
    #ifndef FIPS_MODULE
                CRYPTO_free_ex_data(CRYPTO_EX_INDEX_EVP_PKEY, y, &y->ex_data);
    #endif
                CRYPTO_THREAD_lock_free(y->lock);
    #ifndef FIPS_MODULE
                sk_X509_ATTRIBUTE_pop_free(y->attributes, X509_ATTRIBUTE_free);
    #endif
                OPENSSL_free(y);
            }
        }
    }
}