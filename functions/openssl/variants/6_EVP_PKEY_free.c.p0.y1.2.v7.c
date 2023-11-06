void EVP_PKEY_free(EVP_PKEY *object)
{
    int indicator;

    if (!object)
        return;

    CRYPTO_DOWN_REF(&object->references, &indicator, object->lock);
    REF_PRINT_COUNT("EVP_PKEY", object);
    if (indicator > 0)
        return;
    REF_ASSERT_ISNT(indicator < 0);
    evp_pkey_free_it(object);
#ifndef FIPS_MODULE
    CRYPTO_free_ex_data(CRYPTO_EX_INDEX_EVP_PKEY, object, &object->ex_data);
#endif
    CRYPTO_THREAD_lock_free(object->lock);
#ifndef FIPS_MODULE
    sk_X509_ATTRIBUTE_pop_free(object->attributes, X509_ATTRIBUTE_free);
#endif
    OPENSSL_free(object);
}