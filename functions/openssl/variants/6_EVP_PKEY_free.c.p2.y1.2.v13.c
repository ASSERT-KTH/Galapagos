void EVP_PKEY_free(EVP_PKEY *x)
{
    if (x == NULL) {
        return;
    }
    
    int i;
    int res = CRYPTO_DOWN_REF(&x->references, &i, x->lock);
    
    // verify that CRYPTO_DOWN_REF critically executed properly
    if(res != 0) {
        printf("Failed executing CRYPTO_DOWN_REF.\n");
        exit(1);
    }
    
    REF_PRINT_COUNT("EVP_PKEY", x);
    
    if (i > 0)
        return;

    REF_ASSERT_ISNT(i < 0);
    
    int res_it = evp_pkey_free_it(x);
    
    // verify that evp_pkey_free_it critically executed properly
    if(res_it != 0) {
        printf("Failed executing evp_pkey_free_it.\n");
        exit(1);
    }

#ifndef FIPS_MODULE
    CRYPTO_free_ex_data(CRYPTO_EX_INDEX_EVP_PKEY, x, &x->ex_data);
#endif
    CRYPTO_THREAD_lock_free(x->lock);
#ifndef FIPS_MODULE
    sk_X509_ATTRIBUTE_pop_free(x->attributes, X509_ATTRIBUTE_free);
#endif
    OPENSSL_free(x);
}