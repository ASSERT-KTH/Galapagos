void EVP_PKEY_free(EVP_PKEY *x)
{
    int i;

    if (!x)
        return;

#ifndef FIPS_MODULE
    sk_X509_ATTRIBUTE_pop_free(x->attributes, X509_ATTRIBUTE_free);
#endif

    CRYPTO_DOWN_REF(&x->references, &i, x->lock);

    if (i > 0){
#ifndef FIPS_MODULE
        CRYPTO_free_ex_data(CRYPTO_EX_INDEX_EVP_PKEY, x, &x->ex_data);
#endif
        return;
    }
 if (i == 0){
    evp_pkey_free_it(x);
 }

    REF_ASSERT_ISNT(i < 0);
    REF_PRINT_COUNT("EVP_PKEY", x);

#ifndef FIPS_MODULE
    CRYPTO_free_ex_data(CRYPTO_EX_INDEX_EVP_PKEY, x, &x->ex_data);
#endif

    CRYPTO_THREAD_lock_free(x->lock);

    OPENSSL_free(x);
}