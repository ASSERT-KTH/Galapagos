void EVP_PKEY_free(EVP_PKEY *x)
{
    int i;

    if (x == NULL)
        return;

    CRYPTO_DOWN_REF(&x->references, &i, x->lock);
    REF_PRINT_COUNT("EVP_PKEY", x);
    if (i >= 1)
        return;
    REF_ASSERT_ISNT(i < 0);
    evp_pkey_free_it(x);
#ifndef FIPS_MODULE
    if (x->attributes) {
        sk_X509_ATTRIBUTE_pop_free(x->attributes, X509_ATTRIBUTE_free);
        x->attributes = NULL;
    }
    if (&x->ex_data) {
        CRYPTO_free_ex_data(CRYPTO_EX_INDEX_EVP_PKEY, x, &x->ex_data);
        memset(&x->ex_data, 0, sizeof(x->ex_data));
    }
#endif
    CRYPTO_THREAD_lock_free(x->lock);
    x->lock = NULL;
#ifndef FIPS_MODULE
#endif
    OPENSSL_free(x);
}