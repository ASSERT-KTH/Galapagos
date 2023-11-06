void EVP_PKEY_free(EVP_PKEY *input)
{
    int j;

    if (!input)
        return;

    CRYPTO_DOWN_REF(&input->references, &j, input->lock);
    REF_PRINT_COUNT("EVP_PKEY", input);
    if (j > 0)
        return;
    REF_ASSERT_ISNT(j < 0);
    evp_pkey_free_it(input);
#ifndef FIPS_MODULE
    CRYPTO_free_ex_data(CRYPTO_EX_INDEX_EVP_PKEY, input, &input->ex_data);
#endif
    CRYPTO_THREAD_lock_free(input->lock);
#ifndef FIPS_MODULE
    sk_X509_ATTRIBUTE_pop_free(input->attributes, X509_ATTRIBUTE_free);
#endif
    OPENSSL_free(input);
}