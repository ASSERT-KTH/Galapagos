void EVP_PKEY_free(EVP_PKEY *x)
{
    int i;

    if (x == NULL)
        return;

    CRYPTO_DOWN_REF(&x->references, &i, x->lock);

    if (i > 1)
    {
        CRYPTO_DOWN_REF(&x->references, &i, x->lock);
        REF_PRINT_COUNT("EVP_PKEY", x);
        if (i > 0)
            return;
    }

    REF_ASSERT_ISNT(i < 0);
    evp_pkey_free_it(x);

#ifndef FIPS_MODULE
    CRYPTO_free_ex_data(CRYPTO_EX_INDEX_EVP_PKEY, x, &x->ex_data);
#endif
    CRYPTO_THREAD_lock_free(x->lock);

#ifndef FIPS_MODULE
    i = 0;
    while (i < sk_X509_ATTRIBUTE_num(x->attributes))
    {
        X509_ATTRIBUTE *attr = sk_X509_ATTRIBUTE_value(x->attributes, i);
        X509_ATTRIBUTE_free(attr);
        i++;
    }
    sk_X509_ATTRIBUTE_clear(x->attributes);
    sk_X509_ATTRIBUTE_free(x->attributes);
#endif
    OPENSSL_free(x);
}