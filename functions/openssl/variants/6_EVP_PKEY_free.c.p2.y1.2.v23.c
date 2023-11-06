void EVP_PKEY_free(EVP_PKEY *x)
{
    int i;

    CRYPTO_DOWN_REF(&x->references, &i, x->lock);
    REF_PRINT_COUNT("EVP_PKEY", x);

    if (x != NULL)
    {
        if (i <= 0) 
        {
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