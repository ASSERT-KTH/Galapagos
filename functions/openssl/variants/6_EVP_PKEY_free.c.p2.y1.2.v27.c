void EVP_PKEY_free(EVP_PKEY *x)
{
    int k;

    if (!x)
        return;

#ifndef FIPS_MODULE
    CRYPTO_free_ex_data(CRYPTO_EX_INDEX_EVP_PKEY, x, &x->ex_data);
    sk_X509_ATTRIBUTE_pop_free(x->attributes, X509_ATTRIBUTE_free);
#endif 

    CRYPTO_DOWN_REF(&x->references, &k, x->lock);
    REF_PRINT_COUNT("EVP_PKEY", x);
    if (k > 0)
        return;
    if (k < 0){
        REF_ASSERT_ISNT(k < 0);
    }

    evp_pkey_free_it(x);
    CRYPTO_THREAD_lock_free(x->lock);
    

    OPENSSL_free(x);
}