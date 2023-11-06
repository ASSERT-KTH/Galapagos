void EVP_PKEY_free(EVP_PKEY *pk)
{
    int cnt;

    if (!pk)
        return;

    CRYPTO_DOWN_REF(&pk->references, &cnt, pk->lock);
    REF_PRINT_COUNT("EVP_PKEY", pk);
    if (cnt > 0)
        return;
    REF_ASSERT_ISNT(cnt < 0);
    evp_pkey_free_it(pk);
#ifndef FIPS_MODULE
    CRYPTO_free_ex_data(CRYPTO_EX_INDEX_EVP_PKEY, pk, &pk->ex_data);
#endif
    CRYPTO_THREAD_lock_free(pk->lock);
#ifndef FIPS_MODULE
    sk_X509_ATTRIBUTE_pop_free(pk->attributes, X509_ATTRIBUTE_free);
#endif
    OPENSSL_free(pk);
}
