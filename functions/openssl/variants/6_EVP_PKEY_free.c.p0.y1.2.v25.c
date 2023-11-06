void EVP_PKEY_free(EVP_PKEY *a)
{
    int j;

    if (!a)
        return;
     
    CRYPTO_DOWN_REF(&a->references, &j, a->lock);
    REF_PRINT_COUNT("EVP_PKEY", a);
    if (j > 0)
        return;
    REF_ASSERT_ISNT(j < 0);
    evp_pkey_free_it(a);
#ifndef FIPS_MODULE
    CRYPTO_free_ex_data(CRYPTO_EX_INDEX_EVP_PKEY, a, &a->ex_data);
#endif
    CRYPTO_THREAD_lock_free(a->lock);
#ifndef FIPS_MODULE
    sk_X509_ATTRIBUTE_pop_free(a->attributes, X509_ATTRIBUTE_free);
#endif
    OPENSSL_free(a);
}