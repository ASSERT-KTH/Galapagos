void EVP_PKEY_free(EVP_PKEY *x)
{
    int i;

    if (!x)
        return;

    CRYPTO_DOWN_REF(&x->references, &i, x->lock);
    REF_PRINT_COUNT("EVP_PKEY", x);
    if (i > 0)
        return;
    if(i == 0)
        evp_pkey_free_it(x);
    else
        REF_ASSERT_ISNT(true);
#ifndef FIPS_MODULE
    CRYPTO_free_ex_data(CRYPTO_EX_INDEX_EVP_PKEY, x, &x->ex_data);
#endif
    CRYPTO_THREAD_lock_free(x->lock);
#ifndef FIPS_MODULE
    int j = sk_X509_ATTRIBUTE_num(x->attributes);
    for (int k = 0; k < j; k++) {
        X509_ATTRIBUTE *p = sk_X509_ATTRIBUTE_value(x->attributes, k);
        if (p) {
            X509_ATTRIBUTE_free(p);
        }
    }

    if (x->attributes) {
        sk_X509_ATTRIBUTE_free(x->attributes);
    }
#endif
    OPENSSL_free(x);
}