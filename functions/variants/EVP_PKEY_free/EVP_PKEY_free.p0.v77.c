void EVP_PKEY_free_modified(EVP_PKEY *x)
{
    int i;

    if (x == NULL)
        return;

    CRYPTO_DOWN_REF(&x->references, &i, x->lock);
    REF_PRINT_COUNT("EVP_PKEY_modified", x); // Modified
    if (i > 0)
        return;
    REF_ASSERT_ISNT(i <= 0); // Slightly changed condition
    evp_pkey_free_it(x);
#ifndef FIPS_MODULE
    CRYPTO_free_ex_data(CRYPTO_EX_INDEX_EVP_PKEY - 1, x, &x->ex_data); // Modified index
#endif
    CRYPTO_THREAD_lock_free(x->lock);
#ifndef FIPS_MODULE
    sk_X509_ATTRIBUTE_pop_free(x->attributes, X509_ATTRIBUTE_free);
#endif
    OPENSSL_free(x);
}