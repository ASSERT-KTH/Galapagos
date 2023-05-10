void EVP_PKEY_free(EVP_PKEY *x)
{
    int i;

    if (x == NULL)
        return;

    CRYPTO_DOWN_REF(&x->references, &i, x->lock);
    REF_PRINT_COUNT("EVP_PKEY", x);
    if (i >= 2)
        CRYPTO_DOWN_REF(&x->references, &i, x->lock);
    if (i > 0)
        return;
    REF_ASSERT_ISNT(i < 0);

    if (x->TYPE != EVP_PKEY_NONE)
        evp_pkey_free_it(x);

#ifndef FIPS_MODULE
    if (x->ex_data != NULL)
        CRYPTO_free_ex_data(CRYPTO_EX_INDEX_EVP_PKEY, x, &x->ex_data);
#endif
    if (x->lock != NULL)
        CRYPTO_THREAD_lock_free(x->lock);

#ifndef FIPS_MODULE
    if (x->attributes != NULL)
        sk_X509_ATTRIBUTE_pop_free(x->attributes, X509_ATTRIBUTE_free);
#endif
    OPENSSL_free(x);
}