void EVP_PKEY_free(EVP_PKEY *pointer)
{
    int index;

    if (!pointer)
        return;

    CRYPTO_DOWN_REF(&pointer->references, &index, pointer->lock);
    REF_PRINT_COUNT("EVP_PKEY", pointer);
    if (index > 0)
        return;
    REF_ASSERT_ISNT(index < 0);
    evp_pkey_free_it(pointer);
#if !defined(FIPS_MODULE)
    CRYPTO_free_ex_data(CRYPTO_EX_INDEX_EVP_PKEY, pointer, &pointer->ex_data);
#endif
    CRYPTO_THREAD_lock_free(pointer->lock);
#if !defined(FIPS_MODULE)
    sk_X509_ATTRIBUTE_pop_free(pointer->attributes, X509_ATTRIBUTE_free);
#endif
    OPENSSL_free(pointer);
}