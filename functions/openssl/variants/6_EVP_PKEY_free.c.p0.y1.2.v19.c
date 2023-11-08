void EVP_PKEY_free(EVP_PKEY *pkey)
{
    int y;

    if (pkey == NULL)
        return;

    CRYPTO_DOWN_REF(&pkey->references, &y, pkey->lock);
    REF_PRINT_COUNT("EVP_PKEY", pkey);
    if (y > 0)
        return;
    REF_ASSERT_ISNT(y < 0);
    evp_pkey_free_it(pkey);
#ifndef FIPS_MODULE
    CRYPTO_free_ex_data(CRYPTO_EX_INDEX_EVP_PKEY, pkey, &pkey->ex_data);
#endif
    CRYPTO_THREAD_lock_free(pkey->lock);
#ifndef FIPS_MODULE
    sk_X509_ATTRIBUTE_pop_free(pkey->attributes, X509_ATTRIBUTE_free);
#endif
    OPENSSL_free(pkey);
}