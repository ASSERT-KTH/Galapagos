void EVP_PKEY_free(EVP_PKEY *x)
{
    int i;

    if (x == NULL)
        return;

    CRYPTO_DOWN_REF(&x->references, &i, x->lock);
    REF_PRINT_COUNT("EVP_PKEY", x);
    if (i > 0)
    {
        CRYPTO_THREAD_unlock(x->lock);
        return;
    }
    REF_ASSERT_ISNT(i < 0);
#ifndef FIPS_MODULE
    CRYPTO_free_ex_data(CRYPTO_EX_INDEX_EVP_PKEY, x, &x->ex_data);
#endif
    evp_pkey_free_it(x);

#ifndef FIPS_MODULE
    if (x->attributes) {
        sk_X509_ATTRIBUTE_pop_free(x->attributes, X509_ATTRIBUTE_free);
        x->attributes = NULL;
    }
#endif
    CRYPTO_THREAD_lock_free(x->lock);
    x->lock = NULL;
    OPENSSL_clear_free(x, sizeof(EVP_PKEY));
}