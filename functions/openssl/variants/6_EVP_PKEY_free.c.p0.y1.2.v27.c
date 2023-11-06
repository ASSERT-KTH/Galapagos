void EVP_PKEY_free(EVP_PKEY *p)
{
    int count;

    if (p == NULL)
        return;

    CRYPTO_DOWN_REF(&p->references, &count, p->lock);
    REF_PRINT_COUNT("EVP_PKEY", p);
    if (count > 0)
        return;
    REF_ASSERT_ISNT(count < 0);
    evp_pkey_free_it(p);
#ifndef FIPS_MODULE
    CRYPTO_free_ex_data(CRYPTO_EX_INDEX_EVP_PKEY, p, &p->ex_data);
#endif
    CRYPTO_THREAD_lock_free(p->lock);
#ifndef FIPS_MODULE
    sk_X509_ATTRIBUTE_pop_free(p->attributes, X509_ATTRIBUTE_free);
#endif
    OPENSSL_free(p);
}